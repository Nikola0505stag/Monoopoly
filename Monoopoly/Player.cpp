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
    //if (position < 0)
        //throw std::invalid_argument("Position cannot be negative.");

    this->position = (position % 40 + 40) % 40;
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
    inPrison = !inPrison;
}

void Player::prison()
{
    Dice dice;
    if (inPrison) {
        std::cout << "Choose to pay $100 or try to throw a pair to get out.\n";
		std::cout << "1. Pay $100\n";
		std::cout << "2. Try to throw a pair\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
			setMoney(getMoney() - 100);
			std::cout << "You paid $100 to get out of prison.\n";
			inPrison = false;
			std::cout << "You can now continue your turn!\n";

            dice.rollingADice();
            move(&dice);
		}
        else if (choice == 2) {
            if (dice.sameDice()) {
				std::cout << "You rolled a pair! You are free to go!\n";
                inPrison = false;
                dice.rollingADice();
                move(&dice);
            }
            else {
				std::cout << "You did not roll a pair. You remain in prison.\n";
            }
        }
        else {
			throw std::invalid_argument("Invalid choice. Please choose 1 or 2.");
        }
    }
    else {
        std::cout << "Not in prison, so ready to start your turn!\n";
    }
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
