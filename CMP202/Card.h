#include <string>
#include <iostream>

#pragma once

class Card
{
private:

    int rank;
    enum Suit { Hearts, Diamonds, Spades, Clubs } suit;




public:

	Card();

	void setSuit(int input);

    void setSuit(std::string input);
    std::string getSuit();

    void setRank(int rank);
    int getRank();

	std::pair<std::string,std::string> getCard();

	std::string displayCard();


};

