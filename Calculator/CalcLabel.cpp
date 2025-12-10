#include "CalcLabel.h"

CalcLabel::CalcLabel(std::string Ctitle) :Component(Ctitle) {

}

void CalcLabel::setTitle(std::string Ctitle) {
	Ctitle_ = Ctitle;
}