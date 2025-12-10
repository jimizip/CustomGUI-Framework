#pragma once
#include "Component.h"
class CalcLabel:public Component
{
public:
	CalcLabel(std::string);
	void setTitle(std::string) override;
};

