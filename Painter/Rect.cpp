#include "Rect.h"

Rect::Rect(int l, int t, int r, int b):Figure(l, t, r, b) {
	normalize();
}

void Rect::draw(HDC dc) {
	Rectangle(dc, left_, top_, right_, bottom_);
}