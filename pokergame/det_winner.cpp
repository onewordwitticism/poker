#pragma once
#include "det_winner.h"

// i've essentially written - a fuckton of driver functions - i hate myself
void det_winner(Table& t) {
	vector <vector <Card*> > sevencard_playerpointers = datainitializer_playerscards(t);
	vector < map <Card::suit, int> > player_suit_counts = initialize_player_suit_counts(sevencard_playerpointers);
	vector < map <Card::value, int> > player_value_counts = initialize_player_value_counts(sevencard_playerpointers);

	vector <vector <Card::value> > hands_player1 = hand_functions(player_suit_counts[0], player_value_counts[0]);
	vector <vector <Card::value> > hands_player2 = hand_functions(player_suit_counts[0], player_value_counts[0]);
	
	vector <vector <vector <Card::value> > > All_players_handss = All_player_hands(player_suit_counts, player_value_counts);	
	int x = winner(All_players_handss);

	//enum hand {
//	highcard = 0, pair = 1, two_pair = 2, set = 3,
//	straight = 4, flush = 5, full_house = 6,
//	four_of_a_kind = 7, straight_flush = 8,
//	royal_flush = 9
//};
}

//set not working
int winner(vector <vector <vector <Card::value> > > Player_hands) {
	map <int, int> highest_player_hands;
	int* player_i_highest_hand = new int; *player_i_highest_hand = 0;

	for (int i = 0; i < Player_hands.size(); i++) {
		for (int j = 0; j < 10; j++) { //10 is the amount of different hands you can have;

			if (!(Player_hands[i][j].empty())) {
				*player_i_highest_hand = j; //each players highest hand
			}
			
		}

		highest_player_hands[i] = *player_i_highest_hand;
		cout << highest_player_hands[i] << endl;
		*player_i_highest_hand = 0;
	}
	
	int type_of_hand = -1; int winner = -1;
	vector <std::pair <int, int> > v;

	copy(highest_player_hands.begin(), highest_player_hands.end(), back_inserter(v));
	sort(v.begin(), v.end(), cmp);
	
	// check if there is only 1 of the highest card type;
	if (v[0].second > v[1].second) {
		winner = v[0].first; //player winner number
		type_of_hand = v[0].second;
		//vector hand return; for graphical proof purposes
	}
	else if (v[0].second == v[1].second){
		// check for how many ties there are (just the 1 or 2... 3 ? )
		// write a function
	}



	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " : " << v[i].second << endl;
	}
	
	return 0;
}

vector <vector <vector <Card::value> > > All_player_hands(vector < map <Card::suit, int> > player_suit_counts, vector < map <Card::value, int> > player_value_counts) {
	// note size is limited to amount of players
	
	vector <vector <vector <Card::value> > > temp;
	for (int i = 0; i < player_suit_counts.size(); i++) {
		temp.push_back(hand_functions(player_suit_counts[i], player_value_counts[i]));
	}	
	
	return temp;
}

map <Card::suit, int> make_suit_map(map <Card::suit, int> m, vector <Card*> k) {
	for (int i = 0; i < k.size(); i++) {
		m[k[i]->ret_suit()] += 1;
	}
	return m;
}

map <Card::value, int> make_value_map(map <Card::value, int> m, vector <Card*> k) {
	for (int i = 0; i < k.size(); i++) {
		m[k[i]->ret_value()] += 1;
	}
	return m;
}

// this function returns a pointer vector of vector <Card> pointers.
// this allows generalisation for any x amount of players - as we can just pull from the table each player.
vector <vector <Card*> > datainitializer_playerscards(Table& t) {
	
	vector <vector <Card*> > temp;
	vector <Player*> players = t.ret_players(); //each player, and thus their assosciated cards.
	vector <Card*> Boardcards = t.ret_all_cards(); //board cards.

	for (int i = 0; i < t.ret_num_players(); i++) {
		temp.push_back(add_playercards(Boardcards, players[i]));
	}
	
	return temp;
}

vector < map <Card::suit, int> > initialize_player_suit_counts(vector <vector <Card*> > p) {
	vector < map <Card::suit, int> > temp;
	
	for (int i = 0; i < p.size(); i++) {
		temp.push_back(terrible_initialize_func_suit()); //makes a fresh map <Card::suit, int>
		temp[i] = make_suit_map(temp[i], p[i]);
	}
	return temp;
}

vector < map <Card::value, int> > initialize_player_value_counts(vector <vector <Card*> > p) {
	vector < map <Card::value, int> > temp;

	for (int i = 0; i < p.size(); i++) {
		temp.push_back(terrible_initialize_func_value()); //makes a fresh map <Card::suit, int>
		temp[i] = make_value_map(temp[i], p[i]);
	}
	return temp;
}

vector <Card::value> test_highcard(map <Card::value, int> k) {
	Card::value temp;
	vector <Card::value> highcard;
	map <Card::value, int >::const_iterator it;

	for (it = k.begin(); it != k.end(); ++it) {
		
		if (it->second >= 1) {
			temp = it->first;
		}
	}
	
	highcard.push_back(temp);
	return highcard;
}

// if the size returned is 2 or 3, obviously they have 2 or 3 pairs
vector <Card::value> test_pair(map <Card::value, int> k) { 
	map <Card::value, int >::const_iterator it;
	vector <Card::value> temp;
	
	for (it = k.begin(); it != k.end(); ++it) {

		if (it->second == 2) {
			temp.push_back(it->first);
		}
	}	
	
	return temp;
}

vector <Card::value> test_two_pair(map <Card::value, int> k) {
	map <Card::value, int >::const_iterator it;
	vector <Card::value> temp; 
	vector <Card::value> empty;

	for (it = k.begin(); it != k.end(); ++it) {

		if (it->second == 2) {
			temp.push_back(it->first);
		}
	}

	if (temp.size() < 2) {
		return empty;
	}
	else {
		return temp;
	}
}

vector <Card::value> test_set(map <Card::value, int> k) {
	map <Card::value, int >::const_iterator it;
	vector <Card::value> temp;
	int holder = -1;

	for (it = k.begin(); it != k.end(); ++it) {

		if (it->second == 3) {
			temp.push_back(it->first);
		}
	}

	// swap the set values if one is larger - want 0 to be the highest
	if (temp.size() > 1) {
		if (temp[0] < temp[1]) {
			holder = temp[1];
			temp[1] = temp[0];
			temp[0] = Card::value(holder);
		}
	}

	return temp;
}

vector <Card::value> test_straight(map <Card::value, int> k) {
	map <Card::value, int >::const_iterator it;
	vector <Card::value> temp;
	int count = 0;

	for (it = k.begin(); it != k.end(); ++it) {

		if (it->second == 0) {
			count = 0;
		}

		if (it->second == 1) {
			count += 1;
		}
		
		if (count == 5) {
			temp.push_back(it->first);
		}
		
		if (count == 6) {
			temp[0] = it->first;
		}
		
		if (count == 7) {
			temp[0] = it->first;
		}

	}

	return temp;
}

vector <Card::value> test_flush(map <Card::suit ,int> s, map <Card::value, int> v) {
	
	map <Card::suit, int >::const_iterator its;
	map <Card::value, int >::const_iterator itv;
	vector <Card::value> temp;
	int count = 0;

	for (its = s.begin(); its != s.end(); ++its) {
		
		if (its->second == 5) {
			temp = test_highcard(v);
			
			// has to be the highcard of the flush you retard.  you could be picking one of the other 2
		}

	}
	return temp;
}

// will return [0] as the Card::value of set - [1] will be Card::value of double
// what happens if there are two? different pairs? do autopsy
vector <Card::value> test_full_house(map <Card::value, int> k) {
	
	vector <Card::value> temp;
	vector <Card::value> temp2;
	vector <Card::value> sets = test_set(k); vector <Card::value> sets_return;
	vector <Card::value> pairs = test_pair(k); vector <Card::value> pairs_return;
	
	if (sets.empty()) {
		return temp; //there is no set - therefore no full house, return empty
	} 
	else if (sets.size() == 1) {
		temp.push_back(sets[0]);
	}
	else if (sets.size() == 2) {
		
		if (sets[0] > sets[1]) {
			temp.push_back(sets[0]);
		}
		else {
			temp.push_back(sets[1]);
		}
	}

	if (pairs.empty()) {
		return temp2; //there is no pair - therefore no full house; return an empty
	}
	else if (pairs.size() == 1) {
		temp.push_back(pairs[0]);
	}
	else if (sets.size() == 2) {

		if (pairs[0] > pairs[1]) {
			temp.push_back(pairs[0]);
		}
		else {
			temp.push_back(pairs[1]);
		}
	}

	return temp;
}

vector <Card::value> test_four_of_a_kind(map <Card::value, int> k) {
	map <Card::value, int >::const_iterator it;
	vector <Card::value> temp;

	for (it = k.begin(); it != k.end(); ++it) {

		if (it->second == 4) {
			temp.push_back(it->first);
		}
	}
	return temp;
}

vector <Card::value> test_straight_flush(map <Card::suit, int> s, map <Card::value, int> v) {
	vector <Card::value> temp_straight = test_straight(v);
	vector <Card::value> temp_flush = test_flush(s, v);
	vector <Card::value> empty;

	if (!(temp_straight.empty() && temp_flush.empty())) {
		return temp_flush;
	}
	return empty;
}

vector <Card::value> test_royal_flush(map <Card::suit, int> s, map <Card::value, int> v) {

	map <Card::suit, int >::const_iterator its;
	map <Card::value, int >::const_iterator itv;
	vector <Card::value> temp;
	vector <Card::value> empty;
	int count = 0;

	for (its = s.begin(); its != s.end(); ++its) {

		if (its->second == 5) {
			temp = test_highcard(v);

			if (temp[0] == Card::value::ace) {
				return temp;
			}
			else {
				return empty;
			}
		}
	}
	return empty;
}


//-------------------------------------------------------------------------------------
vector <Card*> add_playercards(vector <Card*> k, Player* p) {
	for (int i = 0; i < 2; i++) {
		k.push_back(p->ret_card_memaddress(i));
	}

	//delete this later
	for (int i = 0; i < k.size(); i++) {
		cout << *k[i];
	}

	return k;
}

void print_suit_map(map <Card::suit, int> k) {
	for (auto elem : k) {
		std::cout << elem.first << " " << elem.second << " " << "\n";
	}
}

void print_value_map(map <Card::value, int> k) {
	for (auto elem : k) {
		std::cout << elem.first << " " << elem.second << " " << "\n";
	}
}



// GENERALIZE THESE - TEMPLATES - FIX
//------------------------------------------------------------------------------------
map <Card::suit, int> terrible_initialize_func_suit() {
	map <Card::suit, int> k;

	k.insert(std::pair <Card::suit, int>(Card::suit::heart, 0));
	k.insert(std::pair <Card::suit, int>(Card::suit::diamond, 0));
	k.insert(std::pair <Card::suit, int>(Card::suit::spade, 0));
	k.insert(std::pair <Card::suit, int>(Card::suit::club, 0));
	return k;
}

map <Card::value, int> terrible_initialize_func_value() {
	map <Card::value, int> k;

	k.insert(std::pair <Card::value, int>(Card::value::two, 0));
	k.insert(std::pair <Card::value, int>(Card::value::three, 0));
	k.insert(std::pair <Card::value, int>(Card::value::four, 0));
	k.insert(std::pair <Card::value, int>(Card::value::five, 0));
	k.insert(std::pair <Card::value, int>(Card::value::six, 0));
	k.insert(std::pair <Card::value, int>(Card::value::seven, 0));
	k.insert(std::pair <Card::value, int>(Card::value::eight, 0));
	k.insert(std::pair <Card::value, int>(Card::value::nine, 0));
	k.insert(std::pair <Card::value, int>(Card::value::ten, 0));
	k.insert(std::pair <Card::value, int>(Card::value::jack, 0));
	k.insert(std::pair <Card::value, int>(Card::value::king, 0));
	k.insert(std::pair <Card::value, int>(Card::value::queen, 0));
	k.insert(std::pair <Card::value, int>(Card::value::ace, 0));
	return k;
}
//------------------------------------------------------------------------------------

// could use function pointers here - however do not have too, and will only ever do once.  Genuinely easier to hard code.
// problem with function pointers is that my input are different for some of them.
vector <vector <Card::value> > hand_functions(map <Card::suit, int> s, map <Card::value, int> v) {
	
	vector <vector <Card::value> > temp;

	temp.push_back(test_highcard(v)); //0
	temp.push_back(test_pair(v)); // 1
	temp.push_back(test_two_pair(v)); // 2
	temp.push_back(test_set(v)); // 3 
	temp.push_back(test_straight(v)); // 4
	//temp.push_back(test_flush(s, v)); // 5
	temp.push_back(test_full_house(v)); // 6
	temp.push_back(test_four_of_a_kind(v)); // 7
	//temp.push_back(test_straight_flush(s, v)); // 8
	//temp.push_back(test_royal_flush(s, v)); // 9

	return temp;
}


bool cmp(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
	return (p1.second < p2.second);
}

















//testingggggggggg
//map <Card::value, int> DUMMYvalue;
//map <Card::suit, int> DUMMYsuit;
//terrible_initialize_func_value(DUMMYvalue);
//terrible_initialize_func_suit(DUMMYsuit);
//
//DUMMYvalue[Card::value::three] = 2;
//DUMMYvalue[Card::value::queen] = 2;
//DUMMYvalue[Card::value::seven] = 2;
//DUMMYvalue[Card::value::two] = 1;
//
//DUMMYsuit[Card::suit::heart] = 5;
//
//vector <Card::value> testy = test_highcard(DUMMYvalue);
////vector <Card::value> testo = test_pair(DUMMYvalue);
//vector <Card::value> flushtest = test_flush(DUMMYsuit, DUMMYvalue);
//
////cout << testy[0] << endl;
//cout << flushtest[0];

//for (int i = 0; i < testo.size(); i++) {
//	cout << testo[i] << endl;
//}






	// all player hand list outcomes; each i is a player, each j is a type of hand, each k is a card in the vector (if non-empty);

	// function pointer to all determining functions ... see what it returns;
	// 1.  TEMPLATES?
	// 4.  make iterator for loop
	// 5.  fix the terrible_initialize_funcs
	// wowowow