#pragma once
#include "Player.h"

const int MAGIC_STRING_OFFSET = 18;
const int MAGIC_STRING_OFFSET2 = 2;

double Player::bet(double amount) { 
	money = money - amount;
	return amount;
}
// can obviously reduce this down to 1 function
double Player::call(double amount) {
	money = money - amount;
	return amount;
}

void Player::check() { return; }
void Player::fold() { in_round = 0; }

void Player::print_cards() {
	for (int i = 0; i < Cards.size(); i++) {
		cout << (Cards[i]);
	}
}

// helper
void print_all_players(vector <Player> p) {
	
	for (int i = 0; i < p.size(); i++) {
		cout << "Player: " << i << " Cards:\n";
		p[i].print_cards();
	}
}

void Player::draw_lines() const {
	for (int i = 0; i < Cards.size(); i++) {
		Cards[i].draw_lines();
	}
}

void Player::receive_Card(Card k) {
	Cards.push_back(k);
}

void Player::def_player_cards() {
	for (int i = 0; i < Cards.size(); i++) {
		Point temp(loc.x + i*(card_w/2), loc.y);
		Cards[i].define_card_edges(temp);
		string s = Cards[i].ret_suitstring() + Cards[i].ret_valuestring();
		Cards[i].set_text(Point(temp.x + MAGIC_STRING_OFFSET2, temp.y + MAGIC_STRING_OFFSET), s);
	}
}

void Player::setplayer_textcolor(Color k) {
	playername.set_color(k);
}

void Player::setplayer_cardcolor(Color k) {
	for (int i = 0; i < Cards.size(); i++) {
		Cards[i].set_colors_(k);
	}
}