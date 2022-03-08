#pragma once
#include <iostream>
#include <string>
#include <vector>

// Created to store global items, add them and define their use that can modify a pet.

class PetItem
{
public:

	PetItem();

	// Future note to self: There may be a problem with the current addEquip/Item function.
	/* If there exist the same item, and add identical, it will fill an entirely different array.
	When this happens, there may be duplicate results on search functions that rely on looping.*/
	// Addendum 1: This issue won't be a problem. The commands here are meant for library of items that the
	// player can have. It should never have duplicates or "itemCounts" in the first place.
	// That's the PetInventory's responsibility.

	bool matchItem(std::string itemName)
	{
		for (size_t i = 0; i < itemList.size(); i++)
		{
			if (itemList[i] == itemName)
			{
				return true;
			}
		}
		return false;
	}

	// Adds an item to the item library.
	void addItem(std::string itemName, int gValue = 0);

	// Adds an item to the item library.
	void addItem(std::string itemName, int ha, int hu, int sl, int so, int fu, int gValue = 0);

	// Removes an item from the item library.
	void removeItem(std::string itemName);

	// Modifies the stat of the item if it exists.
	void defItem(std::string itemName, int ha, int hu, int sl, int so, int fu);

	int getItemGold(std::string itemName)
	{
		for (size_t i = 0; i < itemList.size(); i++)
		{
			if (itemList[i] == itemName)
			{
				return goldValue[i];
			}
		}
		return 0;
	}

	int getItemHappy(size_t itemLocation)
	{
		return itemHappy[itemLocation];
	}
	int getItemHunger(size_t itemLocation)
	{
		return itemHunger[itemLocation];
	}
	int getItemSleep(size_t itemLocation)
	{
		return itemSleep[itemLocation];
	}
	int getItemSocial(size_t itemLocation)
	{
		return itemSocial[itemLocation];
	}
	int getItemFun(size_t itemLocation)
	{
		return itemFun[itemLocation];
	}

	size_t* sItLoc(std::string itemName)
	{
		for (size_t i = 0; i < itemList.size(); i++)
		{
			if (itemName == itemList[i])
			{
				return &i;
			}
			else
			{
				return NULL;
			}
		}
	}



private:
	// std::vector<int> itemFunction; // Removed due to redundancy.
	std::vector<int> itemHappy;
	std::vector<int> itemHunger;
	std::vector<int> itemSleep;
	std::vector<int> itemSocial;
	std::vector<int> itemFun;
	std::vector<int> goldValue;

	std::vector<std::string> itemList;
};

