#include "MyActionListener.h"

MyActionListener::MyActionListener(Frame* parent): ActionListener(parent) {

}
void MyActionListener::ShapePerformed(Component* but) {
	parent_->setFigType(but);
}

void MyActionListener::MenuPerformed(Component* b) {
	parent_->setMenuType(b);
}
