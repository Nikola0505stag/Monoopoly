#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

class Dice
{
	unsigned int firstDie;
	unsigned int secondDie;

public:

	Dice();
	void rollingADice();
	void rollOneDice();

	unsigned int getFirstDie() const;
	unsigned int getSecondDie() const;

	unsigned int getSum() const;
};

