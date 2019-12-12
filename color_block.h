#pragma once
#include <set>
using namespace std;

class color_block
{
// 같은 색 모임 객체
private:
	int color;
	set<class block*> s;
public:
	// 같은 색 모임 객체 생성자
	color_block(class block* b, int color);
	// 해당 객체의 같은 색 모임에 매개변수 같은 색 모임을 합하는 함수
	void insert(set<class block*> s);
	void remove(block* b);
	// 해당 객체의 같은 색 모임 반환 함수
	set<class block *> get_set();
	// 해당 객체의 같은 색 모임 숫자 반환 함수
	int get_set_size();
	int get_color();
};