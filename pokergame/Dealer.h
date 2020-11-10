#pragma once
#include "Deck.h"
#include "Player.h"

class Dealer {
public:
	
	Dealer() {
		d = new Deck;
		current_pot = 0;
	}
	
	~Dealer() { delete d; }
	// so basically I was just returning a regular Deck variable by trying to dereference d and return that.
	// What I think was occurring is that it was making a copy of the dereferenced d, then returning it, but now out of the function it destroyed it.
	// So it's yo; where is the Deck

	Deck* ret_dealerdeck() {return d;}
	//void withdraw_card_player(Player& p);
	
	/*void Deal_Card(Player A);*/
	Card Pop_Card();
	void withdraw_card_table();
	void shuffle() { d->shuffle(); };

private:
	Deck* d;
	double current_pot;
};

// helper function
void Deal_Cards(Dealer* D, Player* P);

