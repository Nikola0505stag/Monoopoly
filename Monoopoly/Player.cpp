#include "Player.h"

Player::Player()
{
    setName("DEFAULT_NAME");
    setMoney(START_MONEY);
    setPosition(0);
}

Player::Player(MyString name)
{
	setName(name);
	setMoney(START_MONEY);
	setPosition(0);
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

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << player.name << "\t" << player.money << "\t" << player.position;
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
