#pragma once
#include "ActionListener.h"
#include "Component.h"


class CalcActionListener:public ActionListener
{
public:
	CalcActionListener(Frame*);
	void CalcPerformed(Component*) override;
};

