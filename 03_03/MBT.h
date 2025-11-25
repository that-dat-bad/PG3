#pragma once
#include "CombatVehicle.h"
class MBT : public CombatVehicle {
public:
	MBT();
	~MBT();
	void Search() const override;
	void Engage() const override;
};

