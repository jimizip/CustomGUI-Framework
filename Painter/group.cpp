#include "group.h"
#include "Rect.h"

Group::Group() {
	//Empty
}

void Group::setBoundary() {
	left_ = top_ = INT_MAX;
	right_ = bottom_ = INT_MIN;
	
	for (auto f : figList) {
		if (f->left_ < this->left_) {
			this->left_ = f->left_;
		}
		if (f->top_ < this->top_) {
			this->top_ = f->top_;
		}
		if (f->right_ > this->right_) {
			this->right_ = f->right_;
		}
		if (f->bottom_ > this->bottom_) {
			this->bottom_ = f->bottom_;
		}
	}
}

void Group::draw(HDC hdc) {
	Rectangle(hdc, left_, top_, right_, bottom_);
	for (Figure* f : figList) {
		f->draw(hdc);
	}
}

void Group::move(int dx, int dy) {
	Figure::move(dx, dy);
	for (Figure* f : figList) {
		f->move(dx, dy);
	}
}

void Group::add(Figure* f) {
	figList.push_back(f);
}

bool Group::isEmpty() {
	return figList.empty();
}