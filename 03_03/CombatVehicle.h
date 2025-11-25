#pragma once
#include<string>
class CombatVehicle {
public:
	 CombatVehicle(const std::string& name);

	virtual ~CombatVehicle();

	virtual void Search() const;

	virtual void Engage() const;
protected:
	std::string name_;
};

