#pragma once
#include "frame.h"
#include "MyButton.h"
#include "figure.h"

class PainterFrame : public Frame {
public:
	PainterFrame();
	PainterFrame(std::wstring, int, int);
	void run() override;
	MyButton* eventHandler(MyEvent e) override;
	void repaint() override;
	void createGroup();
	bool containedIn(Figure* f, MyPoint s, MyPoint e);
	Figure* find(MyPoint p);
	void initialize() override;
	void setFigType(Component*) override;
	void setMenuType(Component*) override;

private:
	MyPoint start_;
	MyPoint end_;
	std::list<Figure*> myFigurelist;
	Component* btnRect;
	Component* btnEllip;
	int figType = 0;
	Component* btnFig;
	Component* btnLine;
	Component* btnStr;
	int menuType = 0;
};