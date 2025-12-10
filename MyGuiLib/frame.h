#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "Component.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class Component;
class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

	// 응용을 위해 필요한 변수

	//std::list<Component*> myButtonlist;
	std::list<Component*> myMenulist;


	
public:
	Frame();
	Frame(std::wstring, int, int);
	virtual void run();

	HDC getDC() {
		return hDC_;
	}
	virtual Component* eventHandler( MyEvent e);
	virtual void repaint();
	void invalidate();
	virtual void initialize() = 0;
	void add(Component*);
	Component* findMenu(MyPoint p);
	virtual void setFigType(Component* b);
	virtual void setCalcType(Component* c);
	virtual void setMenuType(Component*);
	// 그림판용 상수 정의
	static const int RECT_TYPE = 1;
	static const int ELLIP_TYPE = 2;
	static const int FIG_TYPE = 3;
	static const int LINE_TYPE = 4;
	static const int STR_TYPE = 5;
	std::string APPLE_TYPE = "Apple";
	std::string BANANA_TYPE = "Banana";
};