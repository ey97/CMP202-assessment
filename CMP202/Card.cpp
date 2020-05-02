#include "Card.h"

Card::Card()
{
	rank = 1;
	suit = Hearts;
}

void Card::setSuit(int input)
{
	if (input == 1) {
		suit = Hearts;
	}

	else if (input == 2) {
		suit = Diamonds;
	}

	else if (input == 3) {
		suit = Spades;
	}

	else if (input == 4) {
		suit = Clubs;
	}

	else {
		std::cout << "\n\nSuit set Error \n\n";
	}
	
}

std::string Card::getSuit()
{
	switch (suit) {
	case(Hearts): return "Hearts";
		break;

	case(Spades): return "Spades";
		break;

	case(Diamonds): return "Diamonds";
		break;

	case(Clubs): return "Clubs";
		break;


	default: std::cout << "\n\nSuit return error\n\n";
}
}

void Card::setRank(int newRank)
{
	rank = newRank;
}

int Card::getRank()
{
	return rank;
}

std::pair<std::string, std::string> Card::getCard()
{
	std::pair<std::string, std::string> pair;
	pair.first = std::to_string( getRank());
	if (pair.first == "1")
	{
		pair.first = "Ace";
	}

	else if (pair.first == "11")
	{
		pair.first = "Jack";
	}

	else if (pair.first == "12")
	{
		pair.first = "Queen";
	}

	else if (pair.first == "13")
	{
		pair.first = "King";
	}
	pair.second = getSuit();
	return pair;
}

std::string Card::displayCard() {
	std::pair<std::string, std::string> pair;
	pair.first = std::to_string(getRank());
	if (pair.first == "1")
	{
		pair.first = "Ace";
	}

	else if(pair.first == "11")
	{
		pair.first = "Jack";
	}

	else if (pair.first == "12")
	{
		pair.first = "Queen";
	}

	else if (pair.first == "13")
	{
		pair.first = "King";
	}
	pair.second = getSuit();
	return pair.first + "  " + pair.second;
}