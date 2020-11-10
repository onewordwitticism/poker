#include "Card.h"

class Deck {
public:
	Deck();
	
	ostream& print_New_Deck(ostream& os);
	ostream& print_Shuffled_Deck(ostream& os);
	void withdraw_Card();
	
	//void withdraw_Hand();
	//void curr_hands();
	
	Card& operator[](int i) { return New_Deck[i]; }
	void ret_Card(Card::suit suit, Card::value value);
	void withdraw_Card(Card::suit suit, Card::value value);
	bool card_in_deck(Card::suit suit, Card::value value);
	int ret_index(Card::suit suit, Card::value value);
	Card ret_card(int i) { return New_Deck[i]; }
	void shuffle();
	
	Card pop_Card();
private:
	Vector_ref <Card> New_Deck;
	Vector <Card> Shuffled_Deck;
	bool state[52];
};

//ostream& operator<<(ostream& os, Deck& d);
