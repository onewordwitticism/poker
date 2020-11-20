#pragma once
#include "Deck.h"
#include <random>

// just for reference
//enum suit {
//	heart = 0,
//	diamond = 1,
//	spade = 2,
//	club = 3
//};

Deck::Deck() {

	for (int suit = 0; suit < 4; suit++) {
		for(int value = 0; value < 13; value++) {
			New_Deck.push_back(new Card(Card::suit(suit), Card::value(value+2), 1, (suit * 13 + value)));
			state[(suit * 13 + value)] = 1;
		}
	}
}

Deck::~Deck() {
	for (int i = 0; i < New_Deck.size(); i++) {
		delete New_Deck[i];
	}
}

void Deck::shuffle() {

	if (Shuffled_Deck.size() > 0) { Shuffled_Deck.clear(); }

	vector <int> positions;
	for (int i = 0; i < 52; i++) { positions.push_back(i); }

	std::random_device random_dev;
	std::mt19937 generator(random_dev());
	std::shuffle(positions.begin(), positions.end(), generator);

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {

			if (positions[i] == (New_Deck[j]->ret_pos())) {
				Shuffled_Deck.push_back(New_Deck[j]);
			}
		}
	}
}

Card Deck::pop_Card() {
	Card x = *Shuffled_Deck[Shuffled_Deck.size() - 1];
	Shuffled_Deck.pop_back();
	return x;
}

// see this - actually needs to be a sort function
// instead of just brute force linked list checking (lol)
int Deck::ret_index(Card::suit ss, Card::value vv) {
	int index = 0; 

	for (int i = 0; i < 52; i++) {
		if ((New_Deck[i]->ret_suit() == ss) && (New_Deck[i]->ret_value() == vv)) {
			index = i;
			
		}
	}
	return index;
}

void Deck::withdraw_Card(Card::suit suit, Card::value value) {
	int index = ret_index(suit, value);
	state[index] = 0;
}

void Deck::ret_Card(Card::suit suit, Card::value value) {
	int index = ret_index(suit, value);
	state[index] = 1;
}

bool Deck::card_in_deck(Card::suit suit, Card::value value) {
	return state[ret_index(suit, value)];
}

ostream& Deck::print_New_Deck(ostream&os) {
	for (int i = 0; i < New_Deck.size(); i++) {
		os << state[i] << " " << New_Deck[i];
	}
	return os;
}

ostream& Deck::print_Shuffled_Deck(ostream& os) {
	for (int i = 0; i < (Shuffled_Deck.size()); i++) {
		os << state[i] << " " << Shuffled_Deck[i];
	}
	return os;
}