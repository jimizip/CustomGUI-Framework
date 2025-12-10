#pragma once
#include "Windows.h"
#include "Misc.h"

class Figure {
public:
	Figure();
	Figure(int l, int t, int r, int b);
	virtual void draw(HDC) = 0;

	void normalize(); // left가 right보다 큰 경우를 방지하는 함수(top, bottom도)
	virtual void move(int dx, int dy);
	bool inside(MyPoint); //특정 point가 안에 속해있는지 확인하는 함수
	int left_, top_, right_, bottom_;
protected:
	
};