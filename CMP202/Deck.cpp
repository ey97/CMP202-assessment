#include "Deck.h"

Deck::Deck() {
	for (int j = 1; j < 5; j++) {
		for (int i = 1; i < 14; i++) {

			Card* c = new Card;
			c->setRank(i);
			c->setSuit(j);

			deck52.push_back(*c);

			delete c;


		}
	}

	standardDeck = true;
	shuffle();
	changeDeckType();
}

Deck::~Deck() {
//	delete currentDeck;
}

Deck::Deck(int deckCount)
{
	//create as many decks as user specifies
	//shuffle

	for (int k = 0; k < deckCount; k++) {
		for (int j = 1; j < 5; j++) {
			for (int i = 1; i < 14; i++) {

				Card* c = new Card;
				c->setRank(i);
				c->setSuit(j);

				deckUnlim.push_back(*c);

				delete c;


			}
		}
	}

	standardDeck = false;

	shuffle();
	changeDeckType();


}

void Deck::shuffle()
{

	
	
	// random number generator
	std::mt19937 rng(std::random_device{}());



	if (standardDeck) {
		int n = deck52.size();

		for (int i = n - 1; i > 0; i--) {

		}
		std::shuffle(deck52.begin(), deck52.end(),rng); 
	}

	else {
		

		if (!standardDeck) {

			int n = deckUnlim.size();

			std::shuffle(deckUnlim.begin(), deckUnlim.end(), rng);
		}
	}
}

void Deck::find(int n) {
	for (int i = 0; i < deck52.size()-1; i++) {
		if(deck52[i].getRank() == n){
			std::cout << " \n\nfound one\n\n";
		
		}
	}
}

void Deck::changeDeckType() {
	if (standardDeck)
	{
		currentDeck = &deck52;
	}

	else {
		currentDeck = &deckUnlim;
	}

}

Card Deck::deal() {
	auto card = currentDeck->back();
	currentDeck->pop_back();
	return card;
}
