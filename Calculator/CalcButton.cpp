#include "CalcButton.h"
#include "CalcFrame.h"

CalcButton::CalcButton(std::string Ctitle):Component(Ctitle) {

}
void CalcButton::onClick(MyEvent e) {
	OutputDebugStringA("clicked\n");
	listener_->CalcPerformed(this);
}

void CalcButton::setTitle(std::string Ctitle) {

}
