#include "button.h"
#include "frame.h"
#include "ActionListener.h"

Button::Button(std::string title) :Component(title){
	width_ = 70; height_ = 25;
}

/*void Button::draw(HDC hdc) {
	Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	TextOutA(hdc, x_ + 5, y_ + 4, title_.c_str(), title_.length());
}

void Button::setBounds(int x, int y, int width, int height) {
	x_ = x; y_ = y; width_ = width; height_ = height;
}

bool Button::inside(MyPoint p) {
	return inside(p.x_, p.y_);
}

bool Button::inside(int x, int y) {
	return x_ < x&& x < x_ + width_ && y_ < y&& y < y_ + height_;
}

void Button::setParent(Frame* f) {
	parent_ = f;
}*/

void Button::onClick(MyEvent e) {
	OutputDebugStringA("clicked\n");
	//parent_->setFigType(this);
	listener_->ShapePerformed(this);
}
/*
const char* Button::getTitle() {
	return title_.c_str();
}

void Button::addListener(ActionListener* listener) {
	listener_ = listener;
}*/