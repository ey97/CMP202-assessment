#pragma once
#include <utility>
#include <vector>

#include "Card.h"

class Player
{

	std::pair<Card,Card> hand;
	
	public:

		
	std::pair<Card,Card> getHand();
	void setFirst(Card card);
	void setSecond(Card card);


};

