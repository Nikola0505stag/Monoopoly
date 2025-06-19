#include "Dice.h"

Dice::Dice()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	firstDie = 0;
	secondDie = 0;
}

void Dice::rollingADice()
{
	firstDie = rand() % 6 + 1;
	secondDie = rand() % 6 + 1;
}

void Dice::rollOneDice()
{
	firstDie = rand() % 6 + 1;
}

bool Dice::sameDice()
{
	rollingADice();
	std::cout << "First die: " << firstDie << ", Second die: " << secondDie << std::endl;
	if (firstDie == secondDie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int Dice::getFirstDie() const
{
	return firstDie;
}

unsigned int Dice::getSecondDie() const
{
	return secondDie;
}

unsigned int Dice::getSum() const
{
	return secondDie + firstDie;
}
