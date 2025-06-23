#pragma once
#include "RollDiceCommand.h"
#include "HelpCommand.h"
#include "MovePlayerCommand.h"
#include "SellPropertyCommand.h"
#include "BuyCottageCommand.h"
#include "BuyCastleCommand.h"
class Monopoly;
#include <iostream>
#include "MyString.h"


class CommandFactory {


public:
    
    static Command* createCommand(const MyString& commandName, Monopoly& game, size_t index);

};