#include "Circle.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>


Circle::Circle(float radius) {
	radius_ = radius;
}

void Circle::Size() {
	size_ = radius_ * radius_ * static_cast<float>(M_PI);
}

void Circle::Draw() {
	std::cout << "半径" << radius_ << "の円の面積は" << size_<<std::endl;
}

