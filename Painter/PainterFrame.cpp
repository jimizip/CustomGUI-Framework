#include <iostream>
#include "PainterFrame.h"
#include "Rect.h"
#include "Ellip.h"
#include "group.h"
#include "MyActionListener.h"
#include "MyMenu.h"
#include "Line.h"

PainterFrame::PainterFrame() :Frame(L"", 800, 600) {}

PainterFrame::PainterFrame(std::wstring title, int width, int height) :Frame(title, width, height) {}

void PainterFrame::run()
{
	//HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	initialize();
	Frame::run();
}

MyButton* PainterFrame::eventHandler(MyEvent e)
{
	auto j = myMenulist.begin();
	for (int k = 0; k < menuType - 3; k++)
	{
		j++;
	}
	if (Frame::eventHandler(e)) {
		
		invalidate();
	}
	else if (menuType != 0 && ((MyMenu*)(*j))->findButton(e.getPos()) && e.isLButtonUp()) {
		menuType = 0;
		if (((MyMenu*)(*j))->findButton(e.getPos()))
		{
			((MyMenu*)(*j))->findButton(e.getPos())->onClick(e);
		}
		invalidate();
	}
	else {
		if (e.isLButtonUp()) {
			menuType = 0;
		}
		OutputDebugString(L"Event\n");
		std::cout << L"Event\n" << std::endl;
		if (e.isLButtonDown() || e.isRButtonDown()) {
			start_ = e.getPos();
			OutputDebugString(L"Down\n");
		}
		else if (e.isLButtonUp() || e.isRButtonUp()) {
			end_ = e.getPos();

			if (e.isShiftKeyDown()) {
				createGroup();
			}
			else if (e.isCtrlKeyDown()) {
				Figure* f = find(start_);
				if (f) f->move(end_.x_ - start_.x_, end_.y_ - start_.y_);
			}
			else {
				if (figType == RECT_TYPE) {
					myFigurelist.push_back(new Rect(start_.x_, start_.y_, end_.x_, end_.y_));
				}
				else if (figType == ELLIP_TYPE) {
					myFigurelist.push_back(new Ellip(start_.x_, start_.y_, end_.x_, end_.y_));
				}
				else if (figType == STR_TYPE) {
					myFigurelist.push_back(new Line(start_.x_, start_.y_, end_.x_, end_.y_));
				}
			}
			invalidate();
		}
		return nullptr;
	}
}

void PainterFrame::repaint() {
	Frame::repaint();
	if (menuType != 0) {
		auto j = myMenulist.begin();
		for (int k = 0; k < menuType - 3; k++)
		{
			j++;
		}
		((MyMenu*)(*j))->ButtonDraw(hDC_);
	}
	for (auto i = myMenulist.begin(); i != myMenulist.end(); i++) {
		(*i)->draw(hDC_);
	}

	for (auto i = myFigurelist.begin(); i != myFigurelist.end(); ++i) {
		(*i)->draw(hDC_);
	}
}

void PainterFrame::createGroup() {
	std::list<Figure*> temp;
	for (auto f : this->myFigurelist) {
		if (containedIn(f, start_, end_)) {
			temp.push_back(f);
		}
	}
	if (!temp.empty()) {
		Group* g = new Group();
		for (auto f : temp) {
			g->add(f);
			myFigurelist.remove(f);
		}
		g->setBoundary();
		myFigurelist.push_back(g);
	}
}

bool PainterFrame::containedIn(Figure* f, MyPoint start, MyPoint end) {
	return start.x_ < f->left_&& f->right_ < end.x_
		&& start.y_ < f->top_&& f->bottom_ < end.y_;
}

Figure* PainterFrame::find(MyPoint p) {
	for (auto i = myFigurelist.rbegin(); i != myFigurelist.rend(); ++i) {
		if ((*i)->inside(p)) {
			return (*i);
		}
	}
	return nullptr;
}

void PainterFrame::initialize() {
	btnFig = new MyMenu("도형");
	btnLine = new MyMenu("선");
	btnRect = new MyButton("사각형");
	btnEllip = new MyButton("타원");
	btnStr = new MyButton("선");
	add(btnFig);
	add(btnLine);
	btnRect->setParent(this);
	btnEllip->setParent(this);
	btnStr->setParent(this);
	((MyMenu*)btnFig)->addB(btnRect);
	((MyMenu*)btnFig)->addB(btnEllip);
	((MyMenu*)btnLine)->addB(btnStr);
	btnFig->setBounds(10, 10, 70, 25);
	btnLine->setBounds(100, 10, 70, 25);
	btnRect->setBounds(10, 35, 70, 25);
	btnEllip->setBounds(10, 60, 70, 25);
	btnStr->setBounds(100, 35, 70, 25);
	MyActionListener* f;
	f = new MyActionListener(this);
	btnFig->addListener(f);
	btnLine->addListener(f);
	btnRect->addListener(f);
	btnEllip->addListener(f);
	btnStr->addListener(f);
}

void PainterFrame::setFigType(Component* b) {
	OutputDebugStringA(b->getTitle());
	
	if (b == btnRect) {
		figType = RECT_TYPE; //사각형
	}
	else if (b == btnEllip) {
		figType = ELLIP_TYPE; //타원
	}
	else if (b == btnStr) {
		figType = STR_TYPE;
	}
}

void PainterFrame::setMenuType(Component* b) {
	if (b == btnFig) {
		menuType = FIG_TYPE;
	}
	else if (b == btnLine) {
		menuType = LINE_TYPE;
	}
}