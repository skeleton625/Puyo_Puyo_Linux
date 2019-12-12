#include "block.h"
#include "array_2d.h"
#include "color_block.h"

// 같은 색 모임 객체 생성자
color_block::color_block(block* b, int color)
{
	this->color = color;
	this->s = set<block*>();
	if (b != NULL)
		s.insert(b);
}

// 해당 객체의 같은 색 모임에 매개변수 같은 색 모임을 합하는 함수
void color_block::insert(set<block*> blocks)
{
	for (block* b : blocks)
	{
		b->set_group(this);
		s.insert(b);
	}
		
}

void color_block::remove(block* b)
{
	s.erase(b);
}

// 해당 객체의 같은 색 모임 반환 함수
set<block*> color_block::get_set() { return s; }

// 해당 객체의 같은 색 모임 숫자 반환 함수
int color_block::get_set_size() { return s.size(); }
int color_block::get_color() { return color; }