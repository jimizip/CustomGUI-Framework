#include "CalcActionListener.h"

CalcActionListener::CalcActionListener(Frame* parent): ActionListener(parent) {

}
void CalcActionListener::CalcPerformed(Component* com) {
	parent_->setCalcType(com);
}