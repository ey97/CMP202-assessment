#include "Player.h"

std::pair<Card, Card> Player::getHand()
{
	return hand;
}

void Player::setFirst(Card card)
{
	hand.first = card;
}

void Player::setSecond(Card card)
{
	hand.second = card;
}
