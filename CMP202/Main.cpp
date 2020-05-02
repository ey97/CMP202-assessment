#include <iostream>
#include "Deck.h"
#include "Farm.h"
#include "CardTask.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"


bool blackjackCheck(Player* hand) {

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

int run() {

	int results = 0;
	Deck deck(4);
	std::vector<Player*> players;

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
		
		results += 1;
		

	}

	else {
		int count = 0;

		for (int i = 0; i < players.size(); i++) {
			if (blackjackCheck(players[i])) {
				count += 1;
			}
		}

		if (count >= 2) {
			
			results -= 1;
		
		}

		else {
			results += 1;
		}
	}

	return results;
}

void thread_based(int& thread_count, int games, int& won) {

	

	if (thread_count > (int)std::thread::hardware_concurrency()) {
		thread_count = (int)std::thread::hardware_concurrency() - 1;
	}

	if (thread_count < 1) {
		thread_count = 1;

	}

	Farm farm(thread_count);
	int games_dealer_won = 0;


	for (int i = 0; i < games; i++) {
		Task* t = new CardTask;
		farm.add_task(t);
		
	}

	farm.run(won);

	
	
}


int main() {
	bool running = true;
	bool askOnce = false;
	int count = 0;
	int thread_count = 0;
	int game_count = 0;

	while (running)
	{

		//timer needs implimented

		int games_dealer_won = 0;

		if (!askOnce) {

			std::cout << "How many thread would you like to use? maximum is: " << (int)std::thread::hardware_concurrency() - 1 << "\n\n";

			std::cin >> thread_count;

			std::cout << "how many games would you like to simulate?\n";

			std::cin >> game_count;

			std::cout << "how many times do you wish to run the simulation?\n";

			std::cin >> count;

			askOnce = true;

		}

		thread_based(thread_count, game_count, games_dealer_won); //thread function runs as many threads as user entered

		std::cout << "\n\n\nDealer won: " << games_dealer_won << " games of "<< game_count << " using " << thread_count << " threads. \ntook: ";

		games_dealer_won = 0;

		for (int i = 0; i < game_count; i++) {
			games_dealer_won = games_dealer_won + run();
		}

		std::cout << "\nDealer won: " << games_dealer_won << " games of " << game_count << " using single thread. \ntook: ";


		count = count - 1;

		if (count == 0) {
			running = false;
		}


	}
	return 0;



}

