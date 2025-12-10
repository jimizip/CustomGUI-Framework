#pragma once
#include "Component.h"

class Button : public Component
{
public:
	Button(std::string title);
	//void draw(HDC);
	//void setBounds(int x, int y, int width, int height); // 위치, 크기 결정 함수
	//bool inside(MyPoint p);
	//bool inside(int x, int y);
	void onClick(MyEvent e) override;
	//const char* getTitle();
	//void setParent(Frame*);
	//void addListener(ActionListener* listener);
protected:
	/*int x_, y_, width_, height_;
	std::string title_;
	Frame* parent_ = nullptr;
	ActionListener* listener_ = nullptr;*/
};
