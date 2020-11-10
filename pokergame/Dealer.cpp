#include "Dealer.h"
#include "Player.h"

Card Dealer::Pop_Card() {
	Card x = d->pop_Card();
	return x;
}

// function statement in Dealer.h
void Deal_Cards(Dealer* D, Player* P) {

	for (int i = 0; i < 2; i++) {
		P->receive_Card(D->Pop_Card());
	}
}

