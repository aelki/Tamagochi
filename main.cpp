#include "PetStat.h"
#include "PetComponent.h"

/*
Re-fucking doing everything again till I have a better system.



*/

void initPet()
{
	PetStat shibe("Shibe");
	shibe.addInventory("Apple", 1);
	shibe.useItem("Apple");
	

	//shibe.doStuff();
	// 
	// 
	// I need a way to give this thing its own item list and shit.
	// Who's the fucking parent for object creation of shibe.
	// Main -> PetStat/PetInventory
	// Other? -> PetEquipment/PetItem indirectly not attached to PetMain?
	// I'll call this PetComponent, and it also needs a global object that can be shared to everything.

}


int main()
{
	initPet();



	return 0;
}