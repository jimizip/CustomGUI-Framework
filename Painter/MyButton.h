#pragma once
#include "button.h"
class MyButton : public Button {
public:
	MyButton(std::string title);
	void onClick(MyEvent e) override;
};

