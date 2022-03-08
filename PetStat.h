#pragma once
#include <string>
#include "PetInventory.h"

// Note (18:12 - 07/03/2022 - Until there's a need, PetStat will be the "child" aka parent of all other classes.)

class PetStat: public PetInventory // It is possible to add commas to add more "parent"
{
public:

	PetStat(std::string petName)
	{
		name = petName;
		
		initPetStat();
	}

	PetStat()
	{
		initPetStat();
	}

	void useItem(std::string itemName)
	{
		if (getInventoryType(itemName) == 1)
		{
			size_t x = *petLibrary.sItLoc(itemName);
			modHunger(petLibrary.getItemHunger(x));
			modFun(petLibrary.getItemFun(x));
			modSleep(petLibrary.getItemSleep(x));
			modSocial(petLibrary.getItemSocial(x));
			modHappy(petLibrary.getItemHappy(x));
			removeCount(x);
			std::cout << "Item used!" << std::endl;
		}
		else
		{
			std::cout << "ERROR: Item is not usable." << std::endl;
		}

	}

	void initPetStat(int hu = 100, int fu = 100, int sl = 100, int so = 100, int ha = 100);
	void modHunger(int x);
	void modFun(int x);
	void modSleep(int x);
	void modSocial(int x);
	void modHappy(int x);
	void modName(std::string name);

	void resetHunger();
	void resetFun();
	void resetSleep();
	void resetSocial();
	void resetHappy();
	void resetName();

	int outHunger();
	int outFun();
	int outSleep();
	int outSocial();
	int outHappy();
	std::string outName();

private:
	// Lists the current planned stats to interact.
	int mHunger = 9999;
	int mFun = 9999;
	int mSleep = 9999;
	int mSocial = 9999;
	int mHappy = 9999;

	int hunger = 0;
	int fun = 0;
	int sleep = 0;
	int social = 0;
	int happy = 0;

	std::string name = "UNTITLED";
};

