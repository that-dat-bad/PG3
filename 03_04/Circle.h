#pragma once
#include"Ishape.h"
class Circle :public Ishape {
public:
	Circle(float radius);
	void Size() override;
	void Draw() override;
	float radius_;
	float size_ = 0;
};

