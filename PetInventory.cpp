#include "PetInventory.h"

PetInventory::PetInventory()
{
	inventoryVec.resize(10); // Defaults the maximum Inventory.

}



void PetInventory::addInventory(string itemName, int itemCount)
{
	if (petLibrary.matchEquip(itemName))
	{
		addThing(itemName, itemCount, petLibrary.getEquipGold(itemName), 2);
	} 
	else
	if (petLibrary.matchItem(itemName))
	{
		addThing(itemName, itemCount, petLibrary.getItemGold(itemName), 1);
	}
	else
	{
		addThing(itemName, itemCount);
	}
}

// Adds a new item to the inventory list.
void PetInventory::addThing(string itemName, int itemCount, int gValue, int defType)
{
	inventoryVec.push_back(itemName);
	inventoryCount.push_back(itemCount);
	goldValue.push_back(gValue);
	inventoryType.push_back(defType);
}

// Removes the last item on the vector array.
void PetInventory::removeThing()
{
	inventoryVec.pop_back();
	goldValue.pop_back();
	inventoryCount.pop_back();
	inventoryType.pop_back();
}

// Removes item if it exist.
void PetInventory::removeThing(string thingName)
{
	bool removeExist = false;
	for (size_t i = 0; i < inventoryVec.size(); i++)
	{
		if (inventoryVec[i] == thingName)
		{
			inventoryVec[i] = inventoryVec.back();
			goldValue[i] = goldValue.back();
			inventoryCount[i] = inventoryCount.back();
			inventoryType[i] = inventoryType.back();
			inventoryVec.pop_back();
			goldValue.pop_back();
			inventoryCount.pop_back();
			inventoryType.pop_back();
			removeExist = true;
		}
	}
	if (!removeExist)
	{
		std::cout << "ERROR: Item does not exist." << std::endl;
	}
}

void PetInventory::deleteThing(size_t itemLoc)
{
	inventoryVec[itemLoc] = inventoryVec.back();
	goldValue[itemLoc] = goldValue.back();
	inventoryCount[itemLoc] = inventoryCount.back();
	inventoryType[itemLoc] = inventoryType.back();
	inventoryVec.pop_back();
	goldValue.pop_back();
	inventoryCount.pop_back();
	inventoryType.pop_back();
}

void PetInventory::removeThing(string thingName, int itemCount)
{
	bool removeExist = false;
	for (size_t i = 0; i < inventoryVec.size(); i++)
	{
		if (inventoryVec[i] == thingName)
		{
			inventoryCount[i] -= itemCount;
			if (inventoryCount[i] <= 0)
			{
				inventoryVec[i] = inventoryVec.back();
				goldValue[i] = goldValue.back();
				inventoryCount[i] = inventoryCount.back();
				inventoryType[i] = inventoryType.back();
				inventoryVec.pop_back();
				goldValue.pop_back();
				inventoryCount.pop_back();
				inventoryType.pop_back();
			}
			removeExist = true;
		}
	}
	if (!removeExist)
	{
		std::cout << "ERROR: Item does not exist." << std::endl;
	}
}

void PetInventory::modifyThing_gold(string thingName, int value)
{
	bool itemExist = false;
	for (size_t i = 0; i < inventoryVec.size(); i++)
	{
		if (inventoryVec[i] == thingName)
		{
			goldValue[i] = value;
			itemExist = true;
		}
	}
	if (!itemExist)
	{
		std::cout << "ERROR: Item does not exist." << std::endl;
	}
}

// Displays <iostream> inventory with gold value.
void PetInventory::displayInventory()
{
	bool itemExist = false;
	if (inventoryVec[0] != "")
	{
		itemExist = true;
	}
	for (size_t i = 0; i < inventoryVec.size(); i++)
	{
		std::cout << "[" << i + 1 << "]. " << inventoryVec[i] << " - " << goldValue[i] << " Gold" << " - Type: " << inventoryType[i] << std::endl;
	}
	if (!itemExist)
	{
		std::cout << "Inventory is empty!" << std::endl;
	}
}