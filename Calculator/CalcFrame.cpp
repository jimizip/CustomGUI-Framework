#include "CalcFrame.h"
#include "CalcButton.h"
#include "CalcActionListener.h"
#include "CalcLabel.h"

CalcFrame::CalcFrame(std::wstring title, int width, int height) :Frame(title, width, height){

}

void CalcFrame::setCalcType(Component* c) {
	OutputDebugStringA(c->getTitle());
	//CalcType = "jjj";
	if (c == btnApple) {
		CalcType = APPLE_TYPE; //사과
	}
	else if (c == btnBanana) {
		CalcType = BANANA_TYPE; //바나나
	}
	for (auto i = myButtonlist.begin(); i != myButtonlist.end(); i++){
		(*i)->setTitle(CalcType);
	}
}

void CalcFrame::initialize() {
	btnApple = new CalcButton("사과");
	btnBanana = new CalcButton("바나나");
	label = new CalcLabel("");
	add(btnApple);
	add(btnBanana);
	add(label);
	btnApple->setBounds(10, 10, 70, 25);
	btnBanana->setBounds(100, 10, 70, 25);
	label->setBounds(200, 10, 70, 25);
	CalcActionListener* r;
	CalcActionListener* e;
	CalcActionListener* l;
	r = new CalcActionListener(this);
	e = new CalcActionListener(this);
	l = new CalcActionListener(this);
	btnApple->addListener(r);
	btnBanana->addListener(e);
	label->addListener(l);
}

void CalcFrame::run() {
	initialize();
	Frame::run();
}

Component* CalcFrame::eventHandler(MyEvent e)
{
	if(Frame::eventHandler(e)){
		OutputDebugString(L"버튼 눌림\n");
		invalidate();
	}
	else {
		return nullptr;
	}
	
	return nullptr;
}