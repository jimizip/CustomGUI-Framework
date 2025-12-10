#pragma once
#include "ActionListener.h"
#include "frame.h"

class Frame;
class ActionListener;
class Component {
public:
	Component(std::string Ctitle);
	void draw(HDC);
	void setBounds(int x, int y, int width, int height); // 위치, 크기 결정 함수
	bool inside(MyPoint p);
	bool inside(int x, int y);
	virtual void onClick(MyEvent e);
	const char* getTitle();
	void setParent(Frame*);
	void addListener(ActionListener* listener);
	virtual void setTitle(std::string);
protected:
	std::string Ctitle_;
	int x_, y_, width_, height_;
	Frame* parent_ = nullptr;
	ActionListener* listener_ = nullptr;
};