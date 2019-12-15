#include <random>
#include <stdio.h>
#include <unistd.h>	// usleep : sleep function by linux, 1000000 = 1 second
#include <termio.h>	// need for getch function
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

random_device randoms;
mt19937 engine(randoms());
uniform_int_distribution<int> BT(0, 2);
uniform_int_distribution<int> BC(1, 4);

int getch()
{
	int ch;
	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON|ECHO);

	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;

	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);

	return ch;
}

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

int main()
{
	array_2d* bbuyo_obj = new array_2d();

	bbuyo_obj->set_next_block(generate_next_block());
	big_block bb = bbuyo_obj->set_next_block();
	bbuyo_obj->set_next_block(generate_next_block());
	bbuyo_obj->print();

	while (true)
	{
		inp = getch();
		
		if(inp == 'p')
			break;

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
			usleep(1200000);

			int explo = 0;
			while (bbuyo_obj->explosion(explo))
			{
				bbuyo_obj->down_all();
				bbuyo_obj->print();
				usleep(1200000);
			}

			if (!bbuyo_obj->can_make(types))
				break;

			bb = bbuyo_obj->set_next_block();
			bbuyo_obj->set_next_block(generate_next_block());
			down_flag = false;
		}
		bbuyo_obj->print();
	}

	cout << "GAME OVER!!" << '\n';
	cout << "Your Final Score : " << bbuyo_obj->get_score() << '\n';
	return 0;
}
