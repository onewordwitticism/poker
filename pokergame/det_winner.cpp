#pragma once
#include "det_winner.h"

bool myfunction(Card& i, Card& j) { return (i.ret_value() > j.ret_value()); }

void winner_driving_func(Table& t) {
	vector <vector <Card*> > sevencard_playerpointers = datainitializer_playerscards(t);
	vector <results> all_player_hand_results = det_player_hands(sevencard_playerpointers);
	vector <results> winners = det_winner(all_player_hand_results);
	// do something with winners and swap shit around in table etc;
}

vector <results> det_winner(vector <results> player_hands) {
	vector <results> temp;
	hand max = dummy_hand;

	//determine best hand
	for (int i = 0; i < player_hands.size(); i++) {
		if (player_hands[i].type_of_hand > max) {
			max = player_hands[i].type_of_hand;
		}
	}

	//get players who have a hand that good
	for (int i = 0; i < player_hands.size(); i++) {
		player_hands[i].type_of_hand == max;
		temp.push_back(player_hands[i]);
	}

	//if only 1 winner then return - otherwise run tiebreak scenario
	if (temp.size() <= 1) {
		return temp;
	}
	else {
		return(tiebreak(temp));
	}
}

vector <results> tiebreak(vector <results> player_hands) {
	vector <results> temp;
	hand tie_hand = dummy_hand;

	if (tie_hand == 0) { return(highcard_tiebreak(player_hands)); }
	if (tie_hand == 1) { return(pair_tiebreak(player_hands)); }
	if (tie_hand == 2) { return(two_pair_tiebreak(player_hands)); }
	if (tie_hand == 3) { return(set_tiebreak(player_hands)); }
	if (tie_hand == 4) { return(straight_tiebreak(player_hands)); }
	if (tie_hand == 5) { return(flush_tiebreak(player_hands)); }
	if (tie_hand == 6) { return(full_house_tiebreak(player_hands)); }
	if (tie_hand == 8) { return(straight_flush_tiebreak(player_hands)); }
}

vector <results> highcard_tiebreak(vector <results> player_hands) {
	vector <results> temp;
	Card max_card;
	int count = -1;

	if (player_hands.size() == 1) {
		return player_hands;
	}

	// finds the highest card in the player_hands group
	for (int i = 0; i < player_hands.size(); i++) {
		if (player_hands[i].highcards[0].ret_value() > max_card.ret_value()) {
			max_card = player_hands[i].highcards[0];
		}
	}
	
	// if you have that max_card then you can keep playing
	// pops off the front element from each person you are playing against.
	for (int i = 0; i < player_hands.size(); i++) {
		if (player_hands[i].highcards[0].ret_value() == max_card.ret_value()) {
			count += 1;
			temp.push_back(player_hands[i]);
			temp[count].highcards.erase(temp[count].highcards.begin());
		}
	}

	return(highcard_tiebreak(temp));
}

vector <results> pair_tiebreak(vector <results> player_hands) {
	vector <results> temp;
	Card max_pair;
	int count = -1;
	
	//get max pair
	for (int i = 0; i < player_hands.size(); i++) {
		if (player_hands[i].pair_list[0].ret_value() > max_pair.ret_value()) {
			max_pair = player_hands[i].pair_list[0];
		}
	}

	for (int i = 0; i < player_hands.size(); i++) {
		if (player_hands[i].pair_list[0].ret_value() == max_pair.ret_value()) {
			count += 1;
			temp.push_back(player_hands[i]);

			// would have to erase twice
			temp[count].highcards.erase(temp[count].highcards.begin());
		}
	}

	if (temp.size() <= 1) {
		return temp;
	}
	else {
		//temp.size == 2 (cannot have 3 or more, only 4 cards)
		// have to remove the pair from temp.highcards; then make the function that will return the one with the highest kickers
	}
	
}

// need a function that returns the winner (highcards) between 2 vector <Card> lists.


















vector <results> det_player_hands(vector <vector <Card*>> player_cards) {
	vector <results> player_results;
	int i = 0;

	for (auto player : player_cards) {
		player_results.push_back(royal_flush_start(player));
		player_results[i].Player_number = i + 1;
	}

	return player_results;
}

results royal_flush_start(vector <Card*> k) {
	results temp = straight_flush_func(k);

	if (temp.type_of_hand == hand::straight_flush && temp.straight_flush_highcard.ret_value() == Card::value::ace) {
		temp.type_of_hand = hand::royal_flush;
	}

	return temp;
}

results straight_flush_func(vector <Card*> k) {
	results temp = four_of_a_kind_func(k);

	if ((temp.flush_suit != -1) && (temp.straight_highcard.ret_value() != -1)) {

		int count = 0;
		int min = min_size(temp.straight_list, temp.flush_list);

		for (int i = 0; i < min; i++) {

			if (temp.straight_list[i].ret_suit() == temp.flush_suit) {
				temp.straight_flush_list.push_back(temp.straight_list[i]);
				count += 1;
			}

			if (count == 5) {
				temp.type_of_hand = hand::straight_flush;
			}
		}

		temp.straight_flush_list = sorted_highcards_values(temp.straight_flush_list);
		temp.straight_flush_highcard = temp.straight_flush_list[0];

		// put other cards in the straight_flush_list? hmmm maybe
	}
	
	return temp;
}

results four_of_a_kind_func(vector <Card*> k) {
	results temp = full_house_func(k);
	int counts[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	// make the counts
	for (int i = 0; i < k.size(); i++) {
		counts[(k[i]->ret_value() - 2)] += 1;
	}

	for (int i = 0; i < 13; i++) {
		if (counts[i] == 4) {
			temp.type_of_hand = hand::four_of_a_kind;

			// go through cards and add each set card to the set list
			for (int j = 0; j < k.size(); j++) {
				if (k[j]->ret_value() == (i + 2)) {
					temp.four_list.push_back(*k[j]);
				}
			}
		}
	}

	return temp;
}

results full_house_func(vector <Card*> k) {
	results temp = flush_func(k);

	//cannot have 2 unique sets and a unique pair; therefore I don't need to check if sets.size() > 1;
	if ((!temp.set_list.empty()) && (!temp.pair_list.empty())) {
		
		temp.type_of_hand = hand::full_house;
		Card highest_set = temp.set_list[0];
		Card highest_pair = temp.pair_list[0];
		
		// store the set - 
		for (int i = 0; i < 3; i++) {
			temp.full_house_list.push_back(highest_set);
		}

		// store the pair
		for (int i = 0; i < 2; i++) {
			temp.full_house_list.push_back(highest_pair);
		}
	}
	return temp;
}

results flush_func(vector <Card*> k) {
	results temp = straight_func(k);
	int counts[4] = { 0,0,0,0 };

	// get the counts for flush check
	for (int i = 0; i < k.size(); i++) {
		counts[k[i]->ret_suit()] += 1;
	}

	//determine if we have a flush
	for (int i = 0; i < 4; i++) {
		if (counts[i] >= 5) {
			temp.type_of_hand = hand::flush;
			temp.flush_suit = Card::suit(i);
		
			for (int i = 0; i < k.size(); i++) {
				if (k[i]->ret_suit() == temp.flush_suit) {
					temp.flush_list.push_back(*k[i]);
				}
			}

			temp.flush_list = sorted_highcards_values(temp.flush_list);
			temp.flush_highcard = temp.flush_list[0];
			//have option here to chuck on other cards; probably wont
		}
	}
	
	return temp;
}

results straight_func(vector <Card*> k) {
	results temp = set_func(k);
	int count = 0;
	vector <Card> sorted_cards = sorted_highcards_pointers(k);

	//check if we have a straight
	for (int i = 1; i < sorted_cards.size(); i++) {
		if (abs((sorted_cards[i].ret_value() - sorted_cards[i - 1].ret_value())) == 1) {
			temp.straight_list.push_back(sorted_cards[i]);
			temp.straight_list.push_back(sorted_cards[i-1]);
			count += 1;
		}
	}
	
	//if we actually have a straight
	if (count >= 5) {
		temp.type_of_hand = hand::straight;
		temp.straight_list = sorted_highcards_values(temp.straight_list);
		temp.straight_highcard = temp.straight_list[0];
		
		for (int i = 1; i < temp.straight_list.size(); i++) {
			if (temp.straight_list[i] == temp.straight_list[i - 1]) {
				temp.straight_list.erase(temp.straight_list.begin() + i);
			}
		}
	}

	return temp;
}

results set_func(vector <Card*> k) {
	results temp = pairs_func(k);
	int counts[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	// make the counts
	for (int i = 0; i < k.size(); i++) {
		counts[(k[i]->ret_value() - 2)] += 1;
	}

	// if any of the counts == 3, we have a set
	for (int i = 0; i < 13; i++) {
		if (counts[i] == 3) {
			temp.type_of_hand = hand::set;
		
			// go through cards and add each set card to the set list
			for (int j = 0; j < k.size(); j++) {
				if (k[j]->ret_value() == (i + 2)) {
					temp.set_list.push_back(*k[j]);
				}
			}
		}
	}

	if (temp.set_list.size() > 3) {
		temp.set_list = sorted_highcards_values(temp.set_list);
		temp.set_highcard = temp.set_list[0];
	}

	return temp;
} 

results pairs_func(vector <Card*> k) {
	results temp;
	temp.highcards = sorted_highcards_pointers(k);
	temp.type_of_hand = hand::highcard;
	int counts[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	// make the counts
	for (int i = 0; i < k.size(); i++) {
		counts[(k[i]->ret_value() - 2)] += 1;
	}

	for (int i = 0; i < 13; i++) {
		if (counts[i] == 2) {
			temp.type_of_hand = hand::pair;

			// go through cards and add each pair card to the set list
			for (int j = 0; j < k.size(); j++) {
				if (k[j]->ret_value() == (i + 2)) {
					temp.pair_list.push_back(*k[j]);
				}
			}
		}
	}

	if (temp.pair_list.size() > 2) {
		temp.type_of_hand = hand::two_pair;
		temp.pair_list = sorted_highcards_values(temp.pair_list);
		temp.pair_highcard = temp.pair_list[0];
	}

	return temp;
}

vector <Card> sorted_highcards_pointers(vector <Card*> k) {
	vector <Card> temp;

	for (int i = 0; i < k.size(); i++) {
		temp.push_back(Card(*k[i]));
	}

	std::sort(temp.begin(), temp.end(), myfunction);
	return temp;
}

vector <Card> sorted_highcards_values(vector <Card> k) {
	vector <Card> temp;

	for (int i = 0; i < k.size(); i++) {
		temp.push_back(Card(k[i]));
	}

	std::sort(temp.begin(), temp.end(), myfunction);
	return temp;
}

int min_size(vector <Card> a, vector <Card> b) {
	if (a.size() < b.size()) {
		return a.size();
	} 
	else {
		return b.size();
	}
}

Card& highest_val_card(Card& a, Card& b) {
	if (a.ret_value() > b.ret_value()) {
		return a;
	}
	else {
		return b;
	}
}


















































//Shit thats working
//**********************************************************************************************

//for (int i = 0; i < k.size(); i++) {
//	cout << print[i];
//}
//cout << "end";

vector <vector <Card*> > datainitializer_playerscards(Table& t) {

	vector <vector <Card*> > temp;
	vector <Player*> players = t.ret_players(); //each player, and thus their assosciated cards.
	vector <Card*> Boardcards = t.ret_all_cards(); //board cards.

	for (int i = 0; i < t.ret_num_players(); i++) {
		temp.push_back(add_playercards(Boardcards, players[i]));
	}

	return temp;
}

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

//Shit thats working
//**********************************************************************************************