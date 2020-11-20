#pragma once
#include "Simple_window.h"
#include "Table.h"
#include "Dealer.h"
#include "Player.h"
#include "det_winner.h"


const int N_PLAYER = 2;
const int PLAYER_CARD_NO = 2;

int main() { 
	Simple_window win(Point(0, 0), 1920, 1080, "Duke Nukem POKER");

	Table t(Point(150,50), 1200, 700, 2);
	Point player1(400, 400); Point player2(800, 400);
	
	t.add_player(player1, "Captain Stevodore"); t.add_player(player2, "Big Larry Cane");
	
	Dealer Jeeves; Jeeves.shuffle();
	t.setplayer_color(Color::black);
	t.setplayer_cardcolor(Color::dark_green);
	
	Jeeves.Deal_playerCards(t.ret_players());
	t.draw_players();
	win.attach(t);
	t.attache(win);
	
	Jeeves.Deal_Flop(t);
	t.draw_flop(win);
	
	Jeeves.Deal_Turn(t);
	t.draw_turn(win);
	Jeeves.Deal_River(t);
	t.draw_river(win);


	det_winner(t);
	
	win.wait_for_button();
	return 0;
}

// quick note on the deletes; its deleting the players cards, they are copies; NOT on the heap.
// the copied cards were popped off the shuffled deck; ie already deleted.  

