#include "MBT.h"
#include<iostream>
MBT::MBT() : CombatVehicle("MBT") {}
MBT::~MBT() {
}
void MBT::Search()const  {
	std::cout << "砲手用照準器ならびに車長用照準器で索敵..." << std::endl;
}

void MBT::Engage()const {
	std::cout << "直接照準、大口径のAPFSDSまたは多目的弾を発射" << std::endl;
}
