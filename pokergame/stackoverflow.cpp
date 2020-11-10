#pragma once
#include <iostream>
#include <vector>
#include "player.h"
#include <vector>
#include "Deck.h"
#include "Dealer.h"
using namespace std;

string stringsuit(int i);
string stringvalue(int i);
int intsuit(string s);
int intvalue(string s);

class Card {
public:

	enum suit { heart = 0, diamond = 1, spade = 2, club = 3 };
	enum value {
		two = 2, three = 3, four = 4, five = 5,
		six = 6, seven = 7, eight = 8, nine = 9, ten = 10,
		jack = 11, queen = 12, king = 13, ace = 14
	};

	Card(Card::suit ss, Card::value vv, bool indeck, int poss) : s(ss), v(vv), in(indeck), pos(poss) {}
	Card(const Card& k) : s(k.s), v(k.v), in(k.in), pos(k.pos) {}

	suit ret_suit() const { return s; }
	value ret_value() const { return v; }
	bool ret_in() const { return in; }
	int ret_pos() const { return pos; }
	string ret_suitstring() const { return stringsuit(s); }
	string ret_valuestring() const { return stringvalue(v); }

private:
	suit s;
	value v;
	bool in;
	int pos;
};

ostream& operator<<(ostream& os, Card& c);

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

ostream& operator<<(ostream& os, Deck& d);


class Player {
public:
	//note constructor isnt going to work as we need default hand constructor, and also card constructor
	Player(double start_mon) : money(start_mon) {}

	void receive_Card(Card* k) {
		Cards.push_back(k);
		cout << Cards[Cards.size() - 1];
		cout << Cards.size();
	}

	void print_cards() {
		cout << "yyy\n";

		for (int i = 0; i < Cards.size(); i++) {
			cout << (Cards[i]);
			cout << "xxx\n";
		}
	}

private:
	double money;
	Vector_ref <Card> Cards;
};

int main() {

	Dealer Jeeves;
	Player A(10);
	Jeeves.shuffle();
	Jeeves.Deal_Card(A);
	A.print_cards();

	return 0;
}