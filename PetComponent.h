#pragma once
#include "PetEquipment.h"
#include "PetItem.h"

// This header is only for including other components. Do not add code unless necessary.

// (Note: 18:34 - 07/03/2022 - It is necessary. Adding code to fill both these as a thing.)
// Consider naming the code execution below PetLibrary;

class PetLibrary: public PetEquipment, public PetItem
{
public:
	PetLibrary()
	{
		// Equipments. 
		addEquip("Top Hat", "Social Gain", 5, 20);
		addEquip("Sword Gun", "Physical Damage", 15, 35);
		addEquip("Math Book", "Emotional Damage", 20, 15);

		// Items.
		addItem("Apple", 5, 25, -5, 0, 0, 3);
		addItem("Grape", 8, 10, -5, 0, 5, 5);
		addItem("Pizza", 20, 30, -8, -8, 8, 12);
	}

private:
};


// Temp code placement. Consider placing it elsewhere later on.


