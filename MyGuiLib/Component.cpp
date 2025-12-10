#include "Component.h"
#include "button.h"
#include "frame.h"
#include "ActionListener.h"

Component::Component(std::string Ctitle):Ctitle_(Ctitle){
	width_ = 70; height_ = 25;
	x_ = 0; y_ = 0;
}

void Component::draw(HDC hdc) {
	Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	TextOutA(hdc, x_ + 5, y_ + 4, Ctitle_.c_str(), Ctitle_.length());
}

void Component::setBounds(int x, int y, int width, int height) {
	x_ = x; y_ = y; width_ = width; height_ = height;
}

bool Component::inside(MyPoint p) {
	return inside(p.x_, p.y_);
}

bool Component::inside(int x, int y) {
	return x_ < x&& x < x_ + width_ && y_ < y&& y < y_ + height_;
}

void Component::setParent(Frame* f) {
	parent_ = f;
}

void Component::onClick(MyEvent e) {
	OutputDebugStringA("clicked\n");
	//parent_->setFigType(this);
	//listener_->CalcPerformed(this);
}

const char* Component::getTitle() {
	return Ctitle_.c_str();
}

void Component::addListener(ActionListener* listener) {
	listener_ = listener;
}

void Component::setTitle(std::string Ctitle) {

}