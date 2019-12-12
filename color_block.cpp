#include "block.h"
#include "array_2d.h"
#include "color_block.h"

// ���� �� ���� ��ü ������
color_block::color_block(block* b, int color)
{
	this->color = color;
	this->s = set<block*>();
	if (b != NULL)
		s.insert(b);
}

// �ش� ��ü�� ���� �� ���ӿ� �Ű����� ���� �� ������ ���ϴ� �Լ�
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

// �ش� ��ü�� ���� �� ���� ��ȯ �Լ�
set<block*> color_block::get_set() { return s; }

// �ش� ��ü�� ���� �� ���� ���� ��ȯ �Լ�
int color_block::get_set_size() { return s.size(); }
int color_block::get_color() { return color; }