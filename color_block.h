#pragma once
#include <set>
using namespace std;

class color_block
{
// ���� �� ���� ��ü
private:
	int color;
	set<class block*> s;
public:
	// ���� �� ���� ��ü ������
	color_block(class block* b, int color);
	// �ش� ��ü�� ���� �� ���ӿ� �Ű����� ���� �� ������ ���ϴ� �Լ�
	void insert(set<class block*> s);
	void remove(block* b);
	// �ش� ��ü�� ���� �� ���� ��ȯ �Լ�
	set<class block *> get_set();
	// �ش� ��ü�� ���� �� ���� ���� ��ȯ �Լ�
	int get_set_size();
	int get_color();
};