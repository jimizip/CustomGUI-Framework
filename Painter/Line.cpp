#include "Line.h"

Line::Line(int l, int t, int r, int b) :Figure(l, t, r, b) {
	normalize();
}

void Line::draw(HDC dc) {
	MoveToEx(dc, left_, top_, NULL);
	LineTo(dc, right_, bottom_);
}