#pragma once
#include "Card.h"
#include <vector>
#include <iostream>


// could define an array of starting points for 1-10 players.  Then everything would be nice and automatic.
// would have to measure the window appropriately.

// each player should have a bet/check/fold/quit button

const int MAGIC_NAME_OFFSET = -4;

class Player : Shape {
public:
	Player(double start_mon, Point p, string player) : money(start_mon), in_round(0), loc(p),
		playername(Text(Point(loc.x, loc.y + MAGIC_NAME_OFFSET), player)) {
			playername.set_font_size(14);
		}
	
	double bet(double amount);
	double call(double amount);
	void check();
	void fold();
	void print_cards();
	double get_money() { double x = money;}

	
	void receive_Card(Card k);
	void def_player_cards();
	Card& ret_card(int i) { return Cards[i]; }
	Text& ret_playername() { return playername; }
	Card* ret_card_memaddress(int i) { return &Cards[i]; }

	//graphics/colouring/drawing
	void setplayer_textcolor(Color k);
	void setplayer_cardcolor(Color k);
	void draw_lines() const;
private:
	double money;
	Vector <Card> Cards;
	bool in_round;
	Point loc;
	Text playername;

// GUI setup for player	
	//button bet;
	//button check;
	//button fold;
	//button quit;
};

vector <Player> init_players(int num);
void print_all_players(vector <Player> p);