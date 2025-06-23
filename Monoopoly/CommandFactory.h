#pragma once
#include "RollDiceCommand.h"
class Monopoly;
#include <iostream>
#include "MyString.h"


class CommandFactory {


public:
    
    static Command* createCommand(const MyString& commandName, Monopoly& game);

};