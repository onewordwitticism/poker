#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include "player.h"
#include <vector>
using namespace Graph_lib;


// deck will be orientated with formula of; i = 0,1,2,3...51
// i = card_value * 13 + j; where c = {0,1,2,3} and j = {0,1,2,3,...12}
// Hearts = (0*13) + j;
// Diamonds = (1*13) + j ; 
// Spade = (2*13) + j
// Club = (3*13) + j

class Deck {
public:
	Deck();

	
	//void shuffle();
	
	//void withdraw_Hand();
	//void curr_hands();
	
	void ret_Card(Card::suit suit, Card::value value);
	void withdraw_Card(Card::suit suit, Card::value value);
	bool card_in_deck(Card::suit suit, Card::value value);
	int ret_index(Card::suit suit, Card::value value);
	Card ret_card(int i) { return deck1[i]; }
	ostream& print_deck(ostream& os);
	// make destructor
private:
	Vector_ref <Card> deck1;
	bool state[52];
};

ostream& operator<<(ostream& os, Deck& const d);