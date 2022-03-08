#pragma once
#include <string>
#include <vector>
#include <iostream>

#ifndef PET_EQUIPMENT
#define PET_EQUIPMENT

// Created to store global equipments, add them and define their use that can modify a pet.

class PetEquipment
{
public:

	PetEquipment();

	// For Loop: Not used because of problems outputting multiple [i]'s of equipList, m_itemFunction
	/*
	std::string& searchLoop(std::string l_itemName)
	{
		for (size_t i = 0; i < equipList.size(); i++)
		{
			if (equipList[i] == l_itemName)
			{
				return equipList[i];
			}
			else
			{
				std::string none = "NONE";
				return none;
			}
		}
	}

	int searchLoop(std::string l_itemName, std::string retI)
	{
		for (size_t i = 0; i < equipList.size(); i++)
		{
			if (equipList[i] == l_itemName)
			{
				return i;
			}
		}
	}
	*/


	// Getter
	/*std::string getFunction(std::string itemName)
	{
		bool itemExist = false;
		for (size_t i = 0; i < equipList.size(); i++)
		{
			if (itemName == equipList[i])
			{
				return m_itemFunction[i];
				true;
			}
		}
		if (!itemExist)
		{
			std::string none = "NONE";
			std::cout << "ERROR: Equipment does not exist." << std::endl;
			return none;
		}
	}
	*/

	// Found a simpler answer/solution.

	size_t* sEqLoc(std::string itemName);
	std::string getEquipFunc(std::string itemName);

	bool matchEquip(std::string itemName)
	{
		for (size_t i = 0; i < equipList.size(); i++)
		{
			if (equipList[i] == itemName)
			{
				return true;
			}
		}
		return false;
	}

	// Future note to self: There may be a problem with the current addEquip/Item function.
	/* If there exist the same item, and add identical, it will fill an entirely different array.
	When this happens, there may be duplicate results on search functions that rely on looping.*/

	// Adds an item to the item library.
	void addEquip(std::string equipName, std::string equipFunction = "NONE", int functionValue = 0, int goldValue = 0);

	// Removes an item from the item library.
	void removeEquip(std::string equipName);

	// Defines equipment function.
	void defEquip(std::string equipName, std::string equipFunction);

	// Defines specific equipment value (editType: m_functionValue = "fValue", m_goldValue = "gValue").
	void defEquip(std::string equipName, std::string editType, int changeValue);

	int getEquipGold(std::string itemName);

	void listEquip();

private:
	std::vector<std::string> equipList;
	std::vector<std::string> m_itemFunction;
	std::vector<int> m_functionValue;
	std::vector<int> m_goldValue;
};

#endif