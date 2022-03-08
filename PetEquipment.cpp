#include "PetEquipment.h"


PetEquipment::PetEquipment()
{

}


size_t* PetEquipment::sEqLoc(std::string itemName)
{
	for (size_t i = 0; i < equipList.size(); i++)
	{
		if (itemName == equipList[i])
		{
			return &i;
		}
		else
		{
			return NULL;
		}
	}
}

std::string PetEquipment::getEquipFunc(std::string itemName)
{
	return m_itemFunction[*sEqLoc(itemName)];
}

// Adds an item to the item library.
void PetEquipment::addEquip(std::string equipName, std::string equipFunction, int functionValue, int goldValue)
{
	std::cout << "This part is working." << std::endl;
	equipList.push_back(equipName);
	m_itemFunction.push_back(equipFunction);
	m_functionValue.push_back(functionValue);
	m_goldValue.push_back(goldValue);
}

void PetEquipment::listEquip()
{
	std::cout << "===============\nEquipment List\n=========\n";
	for (size_t i = 0; i < equipList.size(); i++)
	{
		std::cout << "[" << i + 1 << "] " << equipList[i] << " - " << m_itemFunction[i] << " - Function Value: " << m_functionValue[i] << " - Gold Value: " << m_goldValue[i] << std::endl;
	}
}


// Removes an item from the item library.
void PetEquipment::removeEquip(std::string equipName)
{
	bool itemExist = false;
	for (size_t i = 0; i < equipList.size(); i++)
	{
		if (equipList[i] == equipName)
		{
			equipList[i] = equipList.back();
			m_itemFunction[i] = m_itemFunction.back();
			m_functionValue[i] = m_functionValue.back();
			m_goldValue[i] = m_goldValue.back();

			equipList.pop_back();
			m_itemFunction.pop_back();
			m_functionValue.pop_back();
			m_goldValue.pop_back();

			itemExist = true;
		}
		if (!itemExist)
		{
			std::cout << "ERROR: Equipment does not exist." << std::endl;
		}
	}
}

// Defines equipment function.
void PetEquipment::defEquip(std::string equipName, std::string equipFunction)
{
	bool itemExist = false;
	for (size_t i = 0; i < equipList.size(); i++)
	{
		if (equipList[i] == equipName)
		{
			m_itemFunction[i] = equipFunction;
			itemExist = true;
		}
		if (!itemExist)
		{
			std::cout << "ERROR: Equipment does not exist." << std::endl;
		}
	}
}

// Defines specific equipment value (editType: m_functionValue = "fValue", m_goldValue = "gValue").
void PetEquipment::defEquip(std::string equipName, std::string editType, int changeValue)
{
	bool itemExist = false;
	for (size_t i = 0; i < equipList.size(); i++)
	{
		if (equipList[i] == equipName)
		{
			if (editType == "fValue")
			{
				m_functionValue[i] = changeValue;
			}
			else
				if (editType == "gValue")
				{
					m_goldValue[i] = changeValue;
				}
				else
				{
					std::cout << "ERROR: Invalid function." << std::endl;
				}
			itemExist = true;
		}
		if (!itemExist)
		{
			std::cout << "ERROR: Item does not exist." << std::endl;
		}
	}
}


int PetEquipment::getEquipGold(std::string itemName)
{
	for (size_t i = 0; i < equipList.size(); i++)
	{
		if (equipList[i] == itemName)
		{
			return m_goldValue[i];
		}
	}
	return 0;
}

