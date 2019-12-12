#include <random>
#include <stdio.h>
#include <unistd.h>	// usleep : sleep function by linux
#include <iostream>
#include "array_2d.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
using namespace std;

int inp = 0;
int types = 0;
int colors[5];
bool down_flag = false;

// 메르센 트위스터 난수 발생기 객체들
random_device random;
mt19937 engine(random());
uniform_int_distribution<int> BT(0, 2);
uniform_int_distribution<int> BC(1, 4);

// 블록 생성 함수
big_block generate_next_block()
{
	types = BT(engine);
	int colors[5];
	for (int i = 0; i < 5; i++)
		colors[i] = BC(engine);

	switch (types)
	{
	case 0:
		return fold_block(colors[0], colors[1], colors[2]);
	case 1:
		return tree_block(colors[0], colors[1], colors[2]);
	case 2:
		return cross_block(colors[0], colors[1], colors[2], colors[3], colors[4]);
	}
	return NULL;
}

// 실제 메인 함수
int main()
{
	cin.tie(false);
	cout.tie(false);
	ios::sync_with_stdio(false);

	// 뿌요뿌요 메인 객체
	array_2d* bbuyo_obj = new array_2d();

	bbuyo_obj->set_next_block(generate_next_block());
	big_block bb = bbuyo_obj->set_next_block();
	bbuyo_obj->set_next_block(generate_next_block());
	bbuyo_obj->print();

	while (true)
	{
		inp = getchar();
		switch (inp)
		{
			case 'a':
				bb.move(0);
				break;
			case 'd':
				bb.move(1);
				break;
			case 's':
				bb.move(2);
				down_flag = true;
				break;
			case 'x':
				bb.down_all();
				down_flag = true;
				break;
			case 'e':
				bb.rotate();
				break;
		}

		if (!bb.can_down() && down_flag)
		{
			bbuyo_obj->down_all();
			bbuyo_obj->print();
			usleep(1200);

			int explo = 0;
			while (bbuyo_obj->explosion(explo))
			{
				bbuyo_obj->down_all();
				bbuyo_obj->print();
				usleep(1200);
			}

			if (!bbuyo_obj->can_make(types))
				break;

			bb = bbuyo_obj->set_next_block();
			bbuyo_obj->set_next_block(generate_next_block());
			down_flag = false;
		}

		else
			bbuyo_obj->print();
	}

	cout << "GAME OVER!!" << '\n';
	cout << "Your Final Score : " << bbuyo_obj->get_score();
	return 0;
}