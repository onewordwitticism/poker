#include "Deck.h"
#include "Card.h"

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
			// note how enumerators have constructors which take in integers and return the string
			deck1.push_back(new Card(Card::suit(suit), Card::value(value+2)));
			state[(suit * 13 + value)] = 1;
		}
	}
}

// see this - actually needs to be a sort function
// instead of just brute force linked list checking (lol)
int Deck::ret_index(Card::suit ss, Card::value vv) {
	int index = 0; 

	for (int i = 0; i < 52; i++) {
		if ((deck1[i].ret_suit() == ss) && (deck1[i].ret_value() == vv)) {
			index = i;
			return index;
		}
	}
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

// finish this off
void shuffle() {
	std::default_random_engine generator; //generates numbers via a seed
	std::uniform_int_distribution <int> distribution(0, 51); 
	int dice_roll = distribution(generator); //somehow maps the seed to the distribution I want.


}



ostream& Deck::print_deck(ostream&os) {
	for (int i = 0; i < deck1.size(); i++) {
		os << state[i] << " " << deck1[i];
	}
	return os;
}
