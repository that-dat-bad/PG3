#include "Rectangle.h"
#include<iostream>

Rectangle::Rectangle(float width, float height) {
	width_ = width;
	height_ = height;
}

void Rectangle::Size() {
	size_ = width_ * height_;
}

void Rectangle::Draw() {
	std::cout << "辺の長さがそれぞれ" << height_ << "," << width_ << "の長さの長方形の面積は" << size_ << std::endl;
}
