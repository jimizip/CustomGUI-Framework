#pragma once
#include "ActionListener.h"

class MyActionListener: public ActionListener
{
public:
	MyActionListener(Frame*);
	void ShapePerformed(Component*) override;
	void MenuPerformed(Component*) override;
};

