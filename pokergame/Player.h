#pragma once
#include "Card.h"
#include <vector>
#include <iostream>

class Player {
public:
	//note constructor isnt going to work as we need default hand constructor, and also card constructor
	Player(double start_mon) : money(start_mon) {}

	void bet();
	void check();
	void fold();
	void quit();
	void get_cards();
	double get_money() { double x = money;}

	// important to note that as we are not passing a pointer; it it creating a COPY of the card input, 
	// and then that copy is called k.  Essentially k = input;
	void receive_Card(Card k) { 	
		Cards.push_back(k);
	}
	
	void print_cards() {
		for (int i = 0; i < Cards.size(); i++) { 
			cout << (Cards[i]);
		}
	}

private:
	double money;
	Vector <Card> Cards;
};