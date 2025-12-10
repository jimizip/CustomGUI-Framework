#pragma once
#include "button.h"
#include "frame.h"

class Frame;
class MyMenu : public Button
{
public:
	MyMenu(std::string title);
	void onClick(MyEvent e) override;
	void ButtonDraw(HDC hDC_);
	void addB(Component*);
	Component* findButton(MyPoint p);

protected:
	std::list<Component*> myButtonlist;
};

