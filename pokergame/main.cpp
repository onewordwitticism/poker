#pragma once
#include "Dealer.h"
#include "Player.h"


// how to define global stuff correctly?  I really need to get my scope downpat - heap and stack.

vector <Player> init_players(int num) {
	vector <Player> p;

	for (int i = 0; i < num; i++) {
		p.push_back(Player(1000));
	}
	return p;
}

int main() {
	

	Dealer Jeeves; 
	
	vector <Player> k = init_players(3);
	Jeeves.shuffle();
	
	//Deal_Cards(&Jeeves, &A);

	return 0;
}


