#include<iostream>
#include"CombatVehicle.h"
#include"MBT.h"
#include"SPAA.h"
int main() {
	CombatVehicle* CVs[2];
	CVs[0] = new MBT;
	CVs[1] = new SPAA;


	for (int i = 0; i < 2; i++) {
		CVs[i]->Search();
		CVs[i]->Engage();
	}


	for (int i = 0; i < 2; i++) {
		delete CVs[i];
	}


	return 0;
}