#pragma once
#include "Card.h"
#include "Table.h"
#include <map>
#include <iterator>

enum hand {
	highcard = 0, pair = 1, two_pair = 2, set = 3,
	straight = 4, flush = 5, full_house = 6,
	four_of_a_kind = 7, straight_flush = 8,
	royal_flush = 9, dummy_hand = -1
};

struct results {

	results() : flush_suit(Card::suit::dummysuit) {}

	//Card() : s(Card::suit::dummysuit), v(Card::value::dummyvalue), in(0), pos(0), t(Text(Point(0, 0), "NULL")) {}
	vector <Card> best_Seven;
	vector <Card> straight_flush_list;
	vector <Card> full_house_list;
	vector <Card> flush_list;
	vector <Card> straight_list;
	vector <Card> four_list;
	vector <Card> set_list;
	vector <Card> pair_list;
	vector <Card> highcards;

	Card::suit flush_suit;
	Card flush_highcard;
	Card straight_flush_highcard;
	Card straight_highcard;
	Card straight_lowcard;
	Card set_highcard;
	Card pair_highcard;
	Card highcard;

	hand type_of_hand;
	int Player_number;
};

vector <vector < std::pair <vector <Card::value>, int> > > All_player_hands(vector < map <Card::suit, int> > player_suit_counts, vector < map <Card::value, int> > player_value_counts, vector <vector <Card*> > p);
vector <vector <Card*> > datainitializer_playerscards(Table& t);
vector < map <Card::suit, int> > initialize_player_suit_counts(vector <vector <Card*> > p);
vector < map <Card::value, int> > initialize_player_value_counts(vector <vector <Card*> > p);
vector < std::pair <vector <Card::value>, int> > hand_functions(map <Card::suit, int> s, map <Card::value, int> v, vector <Card*> p);
vector <Card*> add_playercards(vector <Card*> k, Player* p);
map <Card::value, int> make_value_map(map <Card::value, int> m, vector <Card*> k);
map <Card::suit, int> make_suit_map(map <Card::suit, int> m, vector <Card*> k);
void print_suit_map(map <Card::suit, int> k);
void print_value_map(map <Card::value, int> k);
map <Card::suit, int> terrible_initialize_func_suit();
map <Card::value, int> terrible_initialize_func_value();
void winner_driving_func(Table& t);
std::pair <int, hand> det_tied_hand_winner(vector <std::pair <int, int> >, vector <vector <vector <Card::value> > > Player_hands);

//------------------------------------------------------
//returns the highcard out of the 7;
std::pair <vector <Card::value>, int> test_highcard(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_pair(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_two_pair(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_set(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_straight(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_flush(map <Card::suit, int> s, map <Card::value, int> v, vector <Card*> p);
std::pair <vector <Card::value>, int> test_full_house(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_four_of_a_kind(map <Card::value, int> k);
std::pair <vector <Card::value>, int> test_straight_flush(map <Card::suit, int> s, map <Card::value, int> v, vector <Card*> p);
std::pair <vector <Card::value>, int> test_royal_flush(map <Card::suit, int> s, map <Card::value, int> v, vector <Card*> p);
//------------------------------------------------------

int winner(vector <vector < std::pair <vector <Card::value>, int> > > Player_hands);
bool cmp(const std::pair<int, int>& p1, const std::pair<int, int>& p2);
bool cmp2(const std::pair<int, int>& p1, const std::pair<int, int>& p2);
bool myfunction(Card& i, Card& j);
int min_size(vector <Card> a, vector <Card> b);
Card& highest_val_card(Card& a, Card& b);






//---------------------------------------------------------------------------------------
vector <results> det_player_hands(vector <vector <Card*>> player_cards);
vector <Card> sorted_highcards_pointers(vector <Card*> k);
vector <Card> sorted_highcards_values(vector <Card> k);
vector <results> det_winner(vector <results> player_hands);
vector <results> tiebreak(vector <results> player_hands);
//---------------------------------------------------------------------------------------
results royal_flush_start(vector <Card*> k);
results royal_flush_start(vector <Card*> k);
results straight_flush_func(vector <Card*> k);
results four_of_a_kind_func(vector <Card*> k);
results full_house_func(vector <Card*> k);
results flush_func(vector <Card*> k);
results straight_func(vector <Card*> k);
results set_func(vector <Card*> k);
results pairs_func(vector <Card*> k);
results highcard_func(vector <Card*> k);
//---------------------------------------------------------------------------------------
vector <results> highcard_tiebreak(vector <results> player_hands);
vector <results> pair_tiebreak(vector <results> player_hands);
vector <results> two_pair_tiebreak(vector <results> player_hands);
vector <results> set_tiebreak(vector <results> player_hands);
vector <results> straight_tiebreak(vector <results> player_hands);
vector <results> flush_tiebreak(vector <results> player_hands);
vector <results> full_house_tiebreak(vector <results> player_hands);
vector <results> straight_flush_tiebreak(vector <results> player_hands);