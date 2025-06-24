#pragma once
#include "RollDiceCommand.h"
#include "HelpCommand.h"
#include "MovePlayerCommand.h"
#include "SellPropertyCommand.h"
#include "BuyCottageCommand.h"
#include "BuyCastleCommand.h"
#include "SellCottageCommand.h"
#include "SellCastleCommand.h"
#include "ClearCommand.h"
#include "PrintPlayerCommand.h"
#include "SurrenderCommand.h"
#include "PrintFieldCommand.h"
#include "TradeCommand.h"
class Monopoly;
#include <iostream>
#include "MyString.h"


class CommandFactory {


public:
    
    static Command* createCommand(const MyString& commandName, Monopoly& game, size_t index);

};