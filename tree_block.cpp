#include "tree_block.h"
#include "array_2d.h"
#include "block.h"

tree_block::tree_block(int c1, int c2, int c3) : big_block(1)
{
	block* b1 = new block(c1);
	block* b2 = new block(c2);
	block* b3 = new block(c3);
	b1->set_location(1, 3, true);
	b2->set_location(2, 3, true);
	b3->set_location(3, 3, true);

	v.push_back(b3);
	v.push_back(b2);
	v.push_back(b1);
	array_2d::insert(v);
}