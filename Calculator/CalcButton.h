#pragma once
#include "Component.h"
class CalcButton:public Component
{
public:
	CalcButton(std::string Ctitle);
	void onClick(MyEvent e) override;
	void setTitle(std::string) override;
};

