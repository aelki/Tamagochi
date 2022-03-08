#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PetComponent.h"

using std::string;

// Note (18:32 - 07/03/2022 - Add a feature when you use addThing, check if the item exists in the PetItem library.
// If it exist, replace the goldValue by the determined gold from there.)


class PetInventory
{
public:
	PetLibrary petLibrary;


	PetInventory();

	void addInventory(string itemName, int itemCount);

	// Adds a new item to the inventory list.
	void addThing(string itemName, int itemCount, int gValue = 0, int defType = 0);

	// Removes the last item on the vector array.
	void removeThing();

	// Removes item if it exist.
	void removeThing(string thingName);

	void removeThing(string thingName, int itemCount);

	void deleteThing(size_t itemLoc);

	// Modify a gold value of an existing thing.
	void modifyThing_gold(string thingName, int value);

	// Displays <iostream> inventory with gold value.
	void displayInventory();

	bool matchInventory(std::string itemName)
	{
		for (size_t i = 0; i < inventoryVec.size(); i++)
		{
			if (itemName == inventoryVec[i])
			{
				return true;
			}
		}
		return false;
	}

	int getInventoryType(std::string itemName)
	{
		if (matchInventory(itemName))
		{
			if (*sInvLoc(itemName) >= 999)
			{
				return 0;
			}
			else
			{
				return inventoryType[*sInvLoc(itemName)];
			}
		}
	}

	void removeCount(size_t itemLoc, int itemCount = 1)
	{
		inventoryCount[itemLoc] -= itemCount;
		if (inventoryCount[itemLoc] <= 0)
		{
			deleteThing(itemLoc);
		}
	}

	size_t* sInvLoc(std::string itemName)
	{
		for (size_t i = 0; i < inventoryVec.size(); i++)
		{
			if (itemName == inventoryVec[i])
			{
				return &i;
			}
			else
			{
				size_t nZet = 99999;
				return &nZet;
			}
		}
	}

private:
	std::vector<int> goldValue;
	std::vector<string> inventoryVec;
	std::vector<int> inventoryCount;
	std::vector<string> inventoryCategory;
	std::vector<int> inventoryType; // 1 = Item, 2 = Equipment, 0 = None.

};
