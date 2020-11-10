#pragma once
#include <iostream>
#include "Graph.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;
using namespace std;


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
	
	Card(Card::suit ss, Card::value vv, bool indeck, int poss) : s(ss), v(vv), in(indeck), pos(poss)  {}
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
