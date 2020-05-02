#include "CardTask.h"

void CardTask::run(int& results) {


	Deck deck(4);

	int count;

	for (int i = 0; i < 6; i++)
	{
		Player* p = new Player;
		players.push_back(p);
	}

	for (int i = 0; i < 6; i++) {
		players[i]->setFirst(deck.deal());
		players[i]->setSecond(deck.deal());
	}
	Dealer dealer;

	dealer.setFirst(deck.deal());
	dealer.setSecond(deck.deal());

	if (blackjackCheck(&dealer)) {
		results_lock.lock();
		results += 1;
		results_lock.unlock();
		
	}

	else {
		int count = 0;

		for (int i = 0; i < players.size(); i++) {
			if (blackjackCheck(players[i])) {
				count += 1;
			}
		}

		if (count >= 2) {
			results_lock.lock();
			results -= 1;
			results_lock.unlock();
		}

		else {
			results_lock.lock();
			results += 1;
			results_lock.unlock();
		}
	}

}

void CardTask::run() { return; }

bool CardTask::blackjackCheck(Player* hand) {

	auto card1 = hand->getHand().first.getRank();
	auto card2 = hand->getHand().second.getRank();

	if (card1 == 1 || card1 == 10 || card1 == 11 || card1 == 12 || card1 == 13) {

		if (card2 == 10 || card2 == 11 || card2 == 12 || card2 == 13) {
			return true;
		}

		if (card2 == 1 && card1 != 1)
		{
			return true;
		}

		else { return false; }

	}

	else {
		return false;
	}

}

