#pragma once
#include "frame.h"
#include "Component.h"

class Frame;
class Component;
class ActionListener
{
public:
	ActionListener(Frame*);
	virtual void ShapePerformed(Component*);
	virtual void CalcPerformed(Component*);
	virtual void MenuPerformed(Component*);
protected:
	Frame* parent_ = nullptr;
};

