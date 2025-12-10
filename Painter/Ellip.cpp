#include "Ellip.h"

Ellip::Ellip(int l, int t, int r, int b) :Figure(l, t, r, b) {
	normalize();
}

void Ellip::draw(HDC dc) {
	Ellipse(dc, left_, top_, right_, bottom_);
}