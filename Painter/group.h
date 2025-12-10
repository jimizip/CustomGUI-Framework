#pragma once
#include <list>
#include "figure.h"

class Group : public Figure {
public:
	Group();
	void draw(HDC);
	void setBoundary(); // 그룹 크기 정하는 함수
	void add(Figure* f); // 그룹 안에 다른 도형 넣는 함수
	bool isEmpty(); // 비었는지 알아내는 함수
	void move(int, int) override; // 이동하는 함수
protected:
	std::list<Figure*> figList;
};