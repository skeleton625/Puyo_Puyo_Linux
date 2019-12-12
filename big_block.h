#pragma once
#include <vector>
using namespace std;

class big_block
{
protected:
	int rot_cnt;
	// ū ��Ͽ� ����� ��ϵ� ����
	vector<class block*> v;
	bool can_rotate();
	void rotate_vertex(int& x, int& y);
private:
	// ū ����� �߰� ��� ��ġ ����
	int mid_x, mid_y;
	// ū ����� Ÿ�� ����
	int block_type;
	// ū ����� �̵� ���� ���� Ȯ�� �Լ���
	bool can_left();
	bool can_right();
public:
	// ū ����� ������, �Ҹ���
	big_block();
	big_block(int type);
	~big_block();
	// ū ����� �̵�, ȸ�� �Լ�
	bool move(int input);
	void rotate();
	// ū ����� ��� ����� �̵���Ű�� �Լ�
	void left();
	void right();
	void down();
	void down_all();
	bool can_down();
	// �� ��� ��ȯ �Լ�
	vector<block*> get_blocks();
};