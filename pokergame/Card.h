#pragma once
#include <iostream>
#include <vector>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include "player.h"
#include <vector>

string stringsuit(int i);
string stringvalue(int i);
int intsuit(string s);
int intvalue(string s);

class Card {
public:
	
	enum suit {heart = 0, diamond = 1, spade = 2, club = 3};
	enum value {two = 2, three = 3, four = 4, five = 5,
		six = 6, seven = 7, eight = 8, nine = 9, ten = 10,
		jack = 11, queen = 12, king = 13, ace = 14};
	
	Card(Card::suit ss, Card::value vv) : s(ss), v(vv) {}
	
	suit ret_suit() const { return s; }
	value ret_value() const { return v; }
	string ret_suitstring() const { return stringsuit(s); }
	string ret_valuestring() const { return stringvalue(v); }

	// MAKE DESTRUCTOR - LEARN HOW TO 
private:
	suit s;
	value v;
};

ostream& operator<<(ostream& os, Card& const c);
