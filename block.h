#pragma once
#define SAFE_DELETE(p) { if(p) delete(p); p = NULL; }

class block
{
private:
	bool fixed;
	// ���� ��� ���� ������
	int color;
	int x, y;
	class color_block* group;

	// ����� �պ� �Լ���
	void merge(block *b);
	void split(block *b);
	bool find_merge(block *b);
public:
	// ��� ��ü�� ������, �Ҹ���
	block(int color);
	// ����� ���� ��ȯ �Լ���
	int get_x();
	int get_y();
	int get_color();
	bool get_fixed();
	class color_block *get_group();
	// ����� ���� ���� �Լ���
	void set_color(int color);
	void set_fixed(bool fixed);
	void set_group(class color_block* group);
	void set_location(int x, int y, bool is_init);

	// ����� �̵� �Լ���
	void right();
	void left();
	void down();
	void down_all(bool flag);
	// ���� ����� ��� ���� ���� Ȯ�� �Լ���
	bool can_left();
	bool can_right();
	bool can_down();
	bool can_explosion();
	// ��� �ռ� ���� �ľ� �Լ�
	void can_merge();
};
