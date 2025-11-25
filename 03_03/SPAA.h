#pragma once
#include"CombatVehicle.h"
class SPAA :public CombatVehicle{
public:
	SPAA();
	~SPAA();
	void Search() const override;
	void Engage() const override;
};

