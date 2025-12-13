#include "SPAA.h"
#include<iostream>
SPAA::SPAA() : CombatVehicle("SPAA") {}
SPAA::~SPAA() {
}
void SPAA::Search()const {
	std::cout << "レーダー並びに光学センサーで索敵..." << std::endl;
}

void SPAA::Engage()const {
	std::cout << "中口径の機関砲を用いてドローン、航空機を迎撃" << std::endl;
}
