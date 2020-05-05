#include <iostream>
#include "Deck.h"
#include "Farm.h"
#include "CardTask.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <chrono>


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


	std::vector<long long> multi_thread_times;
	std::vector<long long> single_thread_times;

	std::chrono::high_resolution_clock::time_point start1;
	std::chrono::high_resolution_clock::time_point end1;

	std::chrono::high_resolution_clock::time_point start2;
	std::chrono::high_resolution_clock::time_point end2;

	auto multi_overall = 0;
	auto single_overall = 0;

	int count_store;
	while (running)
	{

		

		int games_dealer_won = 0;

		if (!askOnce) {

			std::cout << "How many thread would you like to use? maximum is: " << (int)std::thread::hardware_concurrency() - 1 << "\n\n";

			std::cin >> thread_count;

			std::cout << "how many games would you like to simulate?\n";

			std::cin >> game_count;

			std::cout << "how many times do you wish to run the simulation?\n";

			std::cin >> count;

			askOnce = true;

			count_store = count;

		}

		start1 = std::chrono::high_resolution_clock::now();

		thread_based(thread_count, game_count, games_dealer_won); //thread function runs as many threads as user entered

		end1 = std::chrono::high_resolution_clock::now();

		auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

		multi_overall += time1;

		std::cout << "\n\n\nDealer won: " << games_dealer_won << " games of "<< count_store << " using " << thread_count << " threads. \ntook: " << time1;

		games_dealer_won = 0;
		start2 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < game_count; i++) {
		
			games_dealer_won = games_dealer_won + run();

		}

		end2 = std::chrono::high_resolution_clock::now();

		auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

		single_overall += time2;

		std::cout << "\nDealer won: " << games_dealer_won << " games of " << count_store << " using single thread. \ntook: " << time2;


		count = count - 1;

		if (count == 0) {
			running = false;
		}


	}

	float multi =(float) (multi_overall / count_store);

	std::cout << "\n\naverage multi-thread time: " << multi <<" ms for "<< count_store << " games" <<  std::endl;

	unsigned long long single = (single_overall / count_store );

	std::cout << "average multi-thread time: " << single << " ms for " << count_store << " games" << std::endl;

	return 0;



}

