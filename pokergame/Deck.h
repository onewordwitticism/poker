#pragma once
#include "Card.h"

class Deck {
public:
	Deck();
	~Deck();
	ostream& print_New_Deck(ostream& os);
	ostream& print_Shuffled_Deck(ostream& os);

	//void withdraw_Hand();
	//void curr_hands();
	
	Card operator[](int i) { return *New_Deck[i]; }
	void ret_Card(Card::suit suit, Card::value value);
	void withdraw_Card(Card::suit suit, Card::value value);
	bool card_in_deck(Card::suit suit, Card::value value);
	int ret_index(Card::suit suit, Card::value value);
	Card ret_card(int i) { return *New_Deck[i]; }
	void shuffle();
	
	Card pop_Card();
private:
	// note - I only allocate new memory for new deck (52 card spaces)
	// for the shuffled deck; I do not allocate new memory; the 48 cards it holds only refer to the memory spaces that are in new_deck.
	// If I was to delete any of the shuffled deck, and then try to delete from new deck, we would have a compile error.
	// So basically, I have 52 new statements for New_Deck, and 52 delete statements.  I can create infinite references to that memory (pointers);
	// which I believe are allocated on the stack, and then destroyed automatically.  But I must specifically delete the heap memory.
	Vector <Card*> New_Deck;
	Vector <Card*> Shuffled_Deck;
	bool state[52];
};

//ostream& operator<<(ostream& os, Deck& d);
