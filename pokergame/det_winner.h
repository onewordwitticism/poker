#pragma once
#include "Card.h"
#include "Table.h"
#include <map>
#include <iterator>

enum hand {
	highcard = 0, pair = 1, two_pair = 2, set = 3,
	straight = 4, flush = 5, full_house = 6,
	four_of_a_kind = 7, straight_flush = 8,
	royal_flush = 9
};

vector <vector <vector <Card::value> > > All_player_hands(vector < map <Card::suit, int> > player_suit_counts, vector < map <Card::value, int> > player_value_counts);
vector <vector <Card*> > datainitializer_playerscards(Table& t);
vector < map <Card::suit, int> > initialize_player_suit_counts(vector <vector <Card*> > p);
vector < map <Card::value, int> > initialize_player_value_counts(vector <vector <Card*> > p);
vector <vector <Card::value> > hand_functions(map <Card::suit, int> s, map <Card::value, int> v);
vector <Card*> add_playercards(vector <Card*> k, Player* p);
map <Card::suit, int> make_value_map(vector <Card*> k);
map <Card::suit, int> make_suit_map(vector <Card*> k);
void print_suit_map(map <Card::suit, int> k);
void print_value_map(map <Card::value, int> k);
map <Card::suit, int> terrible_initialize_func_suit();
map <Card::value, int> terrible_initialize_func_value();
void det_winner(Table& t);

//------------------------------------------------------
//returns the highcard out of the 7;
vector <Card::value> test_highcard(map <Card::value, int> k);
vector <Card::value> test_pair(map <Card::value, int> k);
vector <Card::value> test_two_pair(map <Card::value, int> k);
vector <Card::value> test_set(map <Card::value, int> k);
vector <Card::value> test_straight(map <Card::value, int> k);
vector <Card::value> test_flush(map <Card::suit, int> s, map <Card::value, int> v);
vector <Card::value> test_full_house(map <Card::value, int> k);
vector <Card::value> test_four_of_a_kind(map <Card::value, int> k);
vector <Card::value> test_straight_flush(map <Card::value, int> k);
vector <Card::value> test_royal_flush(map <Card::suit, int> s, map <Card::value, int> v);
//------------------------------------------------------

int winner(vector <vector <vector <Card::value> > > Player_hands);
bool cmp(const std::pair<int, int>& p1, const std::pair<int, int>& p2);