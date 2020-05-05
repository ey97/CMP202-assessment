#include "Card.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <functional>
#pragma once

class Deck
{

	
	std::vector<Card> deckUnlim;
	std::vector<Card> deck52;
	bool standardDeck;
	void changeDeckType();



public:



	Deck();
	~Deck();
	Deck(int deckCount);
	void shuffle();

	void find(int n);


	std::vector<Card>* currentDeck;
	Card deal();
	

};

