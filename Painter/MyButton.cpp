#include "MyButton.h"
#include "PainterFrame.h"

MyButton::MyButton(std::string title) :Button(title) {

}

void MyButton::onClick(MyEvent e) {
	OutputDebugStringA("clicked\n");
	((PainterFrame*)parent_)->setFigType(this);
}
