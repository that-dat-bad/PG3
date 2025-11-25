#include<iostream>
#include"Rectangle.h"
#include"Circle.h"

int main() {
	Ishape* shapes[2]{};
	shapes[0] = new Circle(2.5f);
	shapes[1] = new Rectangle(3.0f, 4.0f);

	for (int i = 0; i < 2; i++) {
		shapes[i]->Size();
		shapes[i]->Draw();
	}
	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
		return 0;
}