#pragma once
#include <vector>
using namespace std;

class big_block
{
protected:
	int rot_cnt;
	// 큰 블록에 연결된 블록들 변수
	vector<class block*> v;
	bool can_rotate();
	void rotate_vertex(int& x, int& y);
private:
	// 큰 블록의 중간 블록 위치 변수
	int mid_x, mid_y;
	// 큰 블록의 타입 변수
	int block_type;
	// 큰 블록의 이동 가능 여부 확인 함수들
	bool can_left();
	bool can_right();
public:
	// 큰 블록의 생성자, 소멸자
	big_block();
	big_block(int type);
	~big_block();
	// 큰 블록의 이동, 회전 함수
	bool move(int input);
	void rotate();
	// 큰 블록의 모든 블록을 이동시키는 함수
	void left();
	void right();
	void down();
	void down_all();
	bool can_down();
	// 빅 블록 반환 함수
	vector<block*> get_blocks();
};