#pragma once
#include "PetItem.h"


PetItem::PetItem()
{

}

// Adds an item to the item library.
void PetItem::addItem(std::string itemName, int gValue)
	{
		itemList.push_back(itemName);
		itemHappy.push_back(0);
		itemHunger.push_back(0);
		itemSleep.push_back(0);
		itemSocial.push_back(0);
		itemFun.push_back(0);
		goldValue.push_back(gValue);
	}
	
// Adds an item to the item library.
void PetItem::addItem(std::string itemName, int ha, int hu, int sl, int so, int fu, int gValue)
{
	itemList.push_back(itemName);
	itemHappy.push_back(ha);
	itemHunger.push_back(hu);
	itemSleep.push_back(sl);
	itemSocial.push_back(so);
	itemFun.push_back(fu);
	goldValue.push_back(gValue);	
}

// Removes an item from the item library.
void PetItem::removeItem(std::string itemName)
{
	bool itemExist = false;
	for (size_t i = 0; i < itemList.size(); i++)
		{
			if (itemName == itemList[i])
			{
				itemList[i] = itemList.back();
				itemHappy[i] = itemHappy.back();
				itemHunger[i] = itemHunger.back();
				itemSleep[i] = itemSleep.back();
				itemSocial[i] = itemSocial.back();
				itemFun[i] = itemFun.back();
				goldValue[i] = goldValue.back();

				itemList.pop_back();
				itemHappy.pop_back();
				itemHunger.pop_back();
				itemSleep.pop_back();
				itemSocial.pop_back();
				itemFun.pop_back();
				goldValue.pop_back();
				itemExist = true;
			}
			if (!itemExist)
			{
				std::cout << "ERROR: Item does not exist." << std::endl;
			}
		}
}

// Modifies the stat of the item if it exists.
void PetItem::defItem(std::string itemName, int ha, int hu, int sl, int so, int fu)
{
	for (size_t i = 0; i < itemList.size(); i++)
	{
		if (itemName == itemList[i])
		{
			itemHappy[i] = ha;
			itemHunger[i] = hu;
			itemSleep[i] = sl;
			itemSocial[i] = so;
			itemFun[i] = fu;
		}
	}
}


