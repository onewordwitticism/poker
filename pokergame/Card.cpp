#pragma once
#include "Card.h"

const int WINDOW_H = 1080;
const int WINDOW_W = 1920;

string stringsuit(int i) { 
	string x = "0";
	if (i == 0) { x = "H"; }
	if (i == 1) { x = "D"; }
	if (i == 2) { x = "S"; }
	if (i == 3) { x = "C"; }
	return x;
}

string stringvalue(int i) { 
	string x = "0";
	if (i == 2) { x = "2"; }
	if (i == 3) { x = "3"; }
	if (i == 4) { x = "4"; }
	if (i == 5) { x = "5"; }
	if (i == 6) { x = "6"; }
	if (i == 7) { x = "7"; }
	if (i == 8) { x = "8"; }
	if (i == 9) { x = "9"; }
	if (i == 10) { x = "10"; }
	if (i == 11) { x = "J"; }
	if (i == 12) { x = "Q"; }
	if (i == 13) { x = "K"; }
	if (i == 14) { x = "A"; }
	return x;
}

ostream& operator<<(ostream& os, Card& c) {
	return (os << "(" << c.ret_suitstring() << "," << c.ret_valuestring() 
		<< "," << c.ret_in() << "," << c.ret_pos() << ")\n");
}


// try not to use; don't think I will have too.
int intsuit(string s) {
	int x = 0;
	if (s == "H") { x = 0; }
	if (s == "D") { x = 1; }
	if (s == "S") { x = 2; }
	if (s == "C") { x = 3; }
	return x;
}

int intvalue(string s) {
	int x = 0;
	if (s == "2") { x = 2; }
	if (s == "3") { x = 3; }
	if (s == "4") { x = 4; }
	if (s == "5") { x = 5; }
	if (s == "6") { x = 6; }
	if (s == "7") { x = 7; }
	if (s == "8") { x = 8; }
	if (s == "9") { x = 9; }
	if (s == "10") { x = 10; }
	if (s == "J") { x = 11; }
	if (s == "Q") { x = 12; }
	if (s == "K") { x = 13; }
	if (s == "A") { x = 14; }
	return x;
}


void Card::draw_lines() const {
	Closed_polyline::draw_lines();
	t.draw_lines();
}

//this is fine
void Card::define_card_edges(Point p) {
	if (p.x > WINDOW_W) { cout << "error point width" << endl; }
	if (p.y > WINDOW_H) { cout << "error point height" << endl; }
	
	add(Point(p.x, p.y));
	add(Point(p.x, p.y + card_h));
	add(Point(p.x + card_w, p.y + card_h));
	add(Point(p.x + card_w, p.y));
}

void Card::set_text(Point p, string text) {
	t.change_point(p); 
	t.set_label(text);
	t.set_font_size(18);
}

void Card::set_colors_(Color k) {
	this->Shape::set_color(k);
	this->t.set_color(k);
}