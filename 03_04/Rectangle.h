#pragma once
#include "Ishape.h"
class Rectangle :public Ishape {
public:
	Rectangle(float width, float height);
	void Size() override;
	void Draw() override;
	float width_;
	float height_;
	float size_ = 0;
};

