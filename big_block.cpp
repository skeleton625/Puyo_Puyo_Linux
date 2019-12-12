#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

big_block::big_block()
{
	rot_cnt = 0;
	block_type = 0;
	mid_x = 0, mid_y = 0;
}

// 큰 블록의 생성자, 소멸자
big_block::big_block(int _type)
{
	rot_cnt = 0;
	this->block_type = _type;
	mid_x = 2, mid_y = 3;
}

big_block::~big_block()
{
	while (!v.empty())
		v.pop_back();
}

// 큰 블록의 이동 가능 여부 확인 함수들
bool big_block::can_left()
{
	for (block* b : v)
	{
		if (!b->can_left())
			return false;
	}
	return true;
}

bool big_block::can_right()
{
	for (block* b : v)
	{
		if (!b->can_right())
			return false;
	}

	return true;
}

bool big_block::can_down()
{
	for (block* b : v)
	{
		if (!b->can_down())
			return false;
	}
	return true;
}

bool big_block::can_rotate()
{
	int x, y;
	for (block* b : v)
	{
		x = b->get_x();
		y = b->get_y();
		rotate_vertex(x, y);
		block* nb = array_2d::get_block(x, y);
		if (nb != NULL && nb->get_fixed())
			return false;
	}
	return true;
}

void big_block::rotate_vertex(int& x, int& y)
{
	int nx = (y - mid_y) * -1;
	int ny = (x - mid_x);
	x = nx + mid_x;
	y = ny + mid_y;
}

// 큰 블록의 이동, 회전 함수
bool big_block::move(int input)
{
	switch (input)
	{
		case 0:
			if (can_left())
			{
				left();
				return true;
			}
			break;
		case 1:
			if (can_right())
			{
				right();
				return true;
			}
			break;
		case 2:
			if (can_down())
			{
				down();
				return true;
			}
			break;
		default:
			return false;
	}
	return false;
}

void big_block::rotate()
{
	if (!can_rotate())
		return;
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());

	int x, y;
	for (block* b : v)
	{
		x = b->get_x();
		y = b->get_y();
		rotate_vertex(x, y);
		b->set_location(x, y, false);
	}

	++rot_cnt;
	if (rot_cnt == 2 || rot_cnt == 4)
	{
		vector<block*> new_v = vector<block*>(v.size(), NULL);
		for (int i = 0; i < v.size(); i++)
			new_v[v.size() - i - 1] = v[i];
		v = new_v;
	}

	if (rot_cnt == 4)
		rot_cnt = 0;
}

// 큰 블록의 모든 블록을 이동시키는 함수
void big_block::left()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->left();
	--mid_y;
}

void big_block::right()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->right();
	++mid_y;
}

void big_block::down()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->down();
	++mid_x;
}

void big_block::down_all()
{
	switch (block_type)
	{
		case 0:
			mid_x = v[1]->get_x();
			break;
		case 1:
			mid_x = v[1]->get_x();
			break;
		case 2:
			mid_x = v[2]->get_x();
			break;
	}
	for (block* b : v)
		b->down_all(false);
}

vector<block*> big_block::get_blocks()
{
	return v;
}