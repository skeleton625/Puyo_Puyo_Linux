#include "block.h"
#include "array_2d.h"
#include "color_block.h"
#include <iostream>

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
// 정의, 반환 함수들
int block::get_color() { return color; }
int block::get_x() { return x; }
int block::get_y() { return y; }
bool block::get_fixed() { return fixed; }
color_block* block::get_group() { return group; }
void block::set_color(int color) { this->color = color; }
void block::set_fixed(bool fixed) { this->fixed = fixed; }
void block::set_group(color_block* group) { this->group = group; }

// 블록 객체 생성자
block::block(int color)
{
	fixed = false;
	x = 0, y = 0;
	this->color = color;
	group = new color_block(this, color);
}

void block::set_location(int x, int y, bool is_init) 
{
	this->x = x, this->y = y; 
	if(!is_init)
		array_2d::insert(x, y, this);
}


// 우로 한 칸 이동
void block::right()
{
	++y;
	array_2d::insert(x, y, this);
}

// 좌로 한 칸 이동
void block::left()
{
	--y;
	array_2d::insert(x, y, this);
}
// 아래로 한 칸 이동
void block::down()
{
	++x;
	array_2d::insert(x, y, this);
}
// 못 내려갈 때까지 이동
void block::down_all(bool flag)
{
	array_2d::delete_block(x, y);

	if (can_down() && flag)
	{
		++x;
		split(this);
	}

	while (can_down())
		++x;
	fixed = true;
	array_2d::insert(x, y, this);
	if(flag) can_merge();
}

// 매개변수 블록과 현재 블록의 그룹을 합침
void block::merge(block *b)
{
	color_block* new_blocks = new color_block(NULL, color);
	color_block* d1 = b->get_group();
	color_block* d2 = group;
	new_blocks->insert(d1->get_set());
	new_blocks->insert(d2->get_set());
	SAFE_DELETE(d1);
	SAFE_DELETE(d2);
}

void block::split(block *b)
{
	set<block*> g = group->get_set();
	set<block*>::iterator it = g.find(b);
	if(it != g.end())
		g.erase(it);
	group = NULL;
	group = new color_block(this, color);
}

// 이도 가능 여부 파악 함수들
bool block::can_down()
{
	block* down_b = array_2d::get_block(x + 1, y);
	if (down_b == NULL || !down_b->fixed)
		return true;
	else
		return false;
}

bool block::can_left()
{
	block* left_b = array_2d::get_block(x, y - 1);
	if (left_b == NULL || !left_b->fixed)
		return true;
	else
		return false;
}

bool block::can_right()
{
	block* right_b = array_2d::get_block(x, y + 1);
	if (right_b == NULL || !right_b->fixed)
		return true;
	else
		return false;
}

void block::can_merge()
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		block* b = array_2d::get_block(nx, ny);
		if (b != NULL && find_merge(b))
		{
			merge(b);
			++flag;
		}
	}
}


bool block::can_explosion()
{
	if (group->get_set_size() > 3 && color != 4)
		return true;
	else
		return false;
}

// ??
bool block::find_merge(block *b)
{
	if (b->color == 0)
		return false;

	set<block*> tmp = group->get_set();
	auto it = tmp.find(b);

	if (it == tmp.end() && b->color == color)
		return true;
	else
		return false;
}