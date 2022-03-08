#include "PetStat.h"


void PetStat::initPetStat(int hu , int fu, int sl, int so, int ha)
{
	mHunger = hu;
	mFun = fu;
	mSleep = sl;
	mSocial = so;
	mHappy = ha;
}


void PetStat::modHunger(int x)
{
	hunger += x;
}
void PetStat::modFun(int x)
{
	fun += x;
}
void PetStat::modSleep(int x)
{
	sleep += x;
}
void PetStat::modSocial(int x)
{
	social += x;
}
void PetStat::modHappy(int x)
{
	happy += x;
}
void PetStat::modName(std::string x)
{
	name = x;
}


void PetStat::resetHunger()
{
	hunger = mHunger;
}
void PetStat::resetFun()
{
	fun = mFun;
}
void PetStat::resetSleep()
{
	sleep = mSleep;
}
void PetStat::resetSocial()
{
	social = mSocial;
}
void PetStat::resetHappy()
{
	happy = mHappy;
}
void PetStat::resetName()
{
	name = "UNTITLED";
}


int PetStat::outHunger()
{
	return hunger;
}
int PetStat::outFun()
{
	return fun;
}
int PetStat::outSleep()
{
	return sleep;
}
int PetStat::outSocial()
{
	return social;
}
int PetStat::outHappy()
{
	return happy;
}
std::string PetStat::outName()
{
	return name;
}