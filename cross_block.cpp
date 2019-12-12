#include "cross_block.h"
#include "array_2d.h"
#include "block.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5) : big_block(2)
{
	block* b1 = new block(c1);
	block* b2 = new block(c2);
	block* b3 = new block(c3);
	block* b4 = new block(c4);
	block* b5 = new block(c5);
	b1->set_location(1, 3, true);
	b2->set_location(2, 2, true);
	b3->set_location(2, 3, true);
	b4->set_location(2, 4, true);
	b5->set_location(3, 3, true);

	v.push_back(b5);
	v.push_back(b2);
	v.push_back(b3);
	v.push_back(b4);
	v.push_back(b1);
	array_2d::insert(v);
}