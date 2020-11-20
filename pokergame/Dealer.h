// be careful of double includes ... always use pragma once
#pragma once
#include "Table.h"
#include "Deck.h"
#include "Player.h"

class Dealer {
public:
	Dealer() {d = new Deck; current_pot = 0; }

	~Dealer() { delete d; }
	Deck* ret_dealerdeck() {return d;}
	Card Pop_Card();
	void shuffle() { d->shuffle(); };

	void Deal_playerCards(vector <Player*> p_list);
	void Deal_Flop(Table& t);
	void Deal_Turn(Table& t);
	void Deal_River(Table& t);

	void det_nextaction();
	void rec_bet();

private:
	Deck* d;
	double current_pot;
};
