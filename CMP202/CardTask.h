#ifndef CARDTASK_H
#define CARDTASK_H

#include <string>
#include <vector>
#include <future>
#include <sstream>


#include "Player.h"
#include "Dealer.h"
#include "Task.h"
#include "Deck.h"

/** Task that prints a message to cout. */
class CardTask : public Task
{



	bool blackjackCheck(Player* hand);
public:

	std::vector<Player> players;

	void run(int& results);



};

#endif