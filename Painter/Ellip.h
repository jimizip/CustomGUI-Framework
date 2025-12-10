#pragma once
#include "figure.h"

class Ellip : public Figure {
public:
	Ellip(int l, int t, int r, int b);
	void draw(HDC) override;
protected:
	//멤버변수는 상속
};