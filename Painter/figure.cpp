#include "figure.h"

Figure::Figure() {
	//Empty
}

Figure::Figure(int l, int t, int r, int b) :left_(l), top_(t), right_(r), bottom_(b) {
	//Empty
}

void Figure::normalize() {
	if (left_ > right_) {
		int t = left_;
		left_ = right_;
		right_ = t;
	}
	if (top_ > bottom_) {
		int t = top_;
		top_ = bottom_;
		bottom_ = t;
	}
}

void Figure::move(int dx, int dy) {
	left_ += dx; right_ += dx;
	top_ += dy; bottom_ += dy;
}

bool Figure::inside(MyPoint p) {
	return left_ < p.x_&& p.x_ < right_
		&& top_ < p.y_&& p.y_ < bottom_;
}