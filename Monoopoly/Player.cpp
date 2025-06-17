#include "Player.h"

Player::Player()
{
    setName("DEFAULT_NAME");
    setMoney(START_MONEY);
    setPosition(0);
    setInPrison(false);
}

Player::Player(MyString name)
{
	setName(name);
	setMoney(START_MONEY);
	setPosition(0);
    setInPrison(false);
}

MyString Player::getName() const
{
    return name;
}

void Player::setName(MyString name)
{
    this->name = name;
}

int Player::getMoney() const
{
    return money;
}

void Player::setMoney(int money) 
{
    this->money = money;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(int position)
{
    if (position < 0)
        throw std::invalid_argument("Position cannot be negative.");
    this->position = position;
}

void Player::setInPrison(bool inPrison)
{
	this->inPrison = inPrison;
}

bool Player::getInPrison() const
{
    return inPrison;
}

void Player::move(Dice* dice)
{
	setPosition(getPosition() + dice->getSum());
}

void Player::prisoner()
{
    setInPrison(getInPrison() -1);
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.name << "\t" << player.money << "\t" << player.position << "\t";
        player.inPrison? os <<"In Prison!" : os <<"Not in prison!";
    return os;
}

std::istream& operator>>(std::istream& is, Player& player)
{
	char buffer[1024];
	is.getline(buffer, 1024, '\n');
	player.name = MyString(buffer);
	//is >> player.money >> player.position;

    return is;
}
