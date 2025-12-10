#pragma once
#include "frame.h"

class CalcFrame: public Frame
{
public:
	CalcFrame(std::wstring title, int width, int height);
	void setCalcType(Component* c) override;
	void initialize() override;
	void run() override;
	Component* eventHandler(MyEvent e) override;
private:
	Component* label;
	Component* btnApple;
	Component* btnBanana;
	std::string CalcType;
};

