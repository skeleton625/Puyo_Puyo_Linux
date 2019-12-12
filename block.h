#pragma once
#define SAFE_DELETE(p) { if(p) delete(p); p = NULL; }

class block
{
private:
	bool fixed;
	// 현재 블록 정보 변수들
	int color;
	int x, y;
	class color_block* group;

	// 블록의 합병 함수들
	void merge(block *b);
	void split(block *b);
	bool find_merge(block *b);
public:
	// 블록 객체의 생성자, 소멸자
	block(int color);
	// 블록의 정보 반환 함수들
	int get_x();
	int get_y();
	int get_color();
	bool get_fixed();
	class color_block *get_group();
	// 블록의 정보 설정 함수들
	void set_color(int color);
	void set_fixed(bool fixed);
	void set_group(class color_block* group);
	void set_location(int x, int y, bool is_init);

	// 블록의 이동 함수들
	void right();
	void left();
	void down();
	void down_all(bool flag);
	// 현재 블록의 기능 가능 여부 확인 함수들
	bool can_left();
	bool can_right();
	bool can_down();
	bool can_explosion();
	// 블록 합성 여부 파악 함수
	void can_merge();
};
