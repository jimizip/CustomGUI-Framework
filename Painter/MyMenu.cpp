#include "MyMenu.h"
#include "ActionListener.h"
#include "frame.h"

MyMenu::MyMenu(std::string title) :Button(title) {}

void MyMenu::onClick(MyEvent e) {
	OutputDebugStringA("clicked\n");
	listener_->MenuPerformed(this);
}

void MyMenu::ButtonDraw(HDC hDC_) {
	for (auto i = myButtonlist.begin(); i != myButtonlist.end(); i++) {
		(*i)->draw(hDC_);
	}
}

void MyMenu::addB(Component* b) {
	myButtonlist.push_back(b);
}

Component* MyMenu::findButton(MyPoint p) {
	for (auto b : myButtonlist) {
		if (b->inside(p)) {
			return b;
		}
	}
	return nullptr;
}