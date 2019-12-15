#include <set>
#include <vector>
#include "big_block.h"
using namespace std;

#define W 7
#define H 14
#define SAFE_DELETE(p) { if(p) delete(p); p = NULL; }

class array_2d
{
private:
	big_block next_block;
	
	int color[5] = { 97, 34, 32, 31, 90 };
	int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	static int score;
	static class block* block_array[H][W];
	static class block* next_block_array[W][W];
	static set<class color_block*> explosion_s;
	void remove_explosion();
public:
	array_2d();	
	bool can_make(int types);
	void print();
	void set_color(int back);
	void set_next_block(big_block bb);
	big_block set_next_block();
	int get_score();
	int explosion(int& cnt);
	void down_all();
	static void insert(vector<class block*> v);
	static void insert(int x, int y, class block* b);
	static void insert_explosion(class color_block* group);
	static block *get_block(int x, int y);
	static void delete_block(int x, int y);
};
