#pragma once
#include "figure.h"
class Line :
    public Figure
{
public:
	Line(int l, int t, int r, int b);
	void draw(HDC) override;
};

