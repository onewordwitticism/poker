#include "Dealer.h"
#include "Player.h"

void det_nextaction() {}

Card Dealer::Pop_Card() {
	Card x = d->pop_Card();
	return x;
}

void Dealer::Deal_playerCards(vector <Player*> p_list) {
	int num_cards = 2;

	//for (int i = 0; i < p_list.size(); i++) {
	//	for (int j = 0; j < num_cards; j++) {
	//		p_list[i]->receive_Card(this->Pop_Card());
	//	}
	//}

	p_list[0]->receive_Card(Card(Card::suit::spade, Card::value::king, 0, 0));
	p_list[0]->receive_Card(Card(Card::suit::spade, Card::value::three, 0, 0));
	p_list[1]->receive_Card(Card(Card::suit::spade, Card::value::ace, 0, 0));
	p_list[1]->receive_Card(Card(Card::suit::spade, Card::value::king, 0, 0));

	return;
}

void Dealer::Deal_Flop(Table& t) {
	//for (int i = 0; i < 3; i++) {
	//	t.receive_Flop(this->Pop_Card());
	//}

	t.receive_Flop(Card(Card::suit::spade, Card::value::queen, 0, 0));
	t.receive_Flop(Card(Card::suit::spade, Card::value::jack, 0, 0));
	t.receive_Flop(Card(Card::suit::spade, Card::value::ten, 0, 0));
}

void Dealer::Deal_Turn(Table& t) {
	//t.receive_Turn(this->Pop_Card());
	t.receive_Turn(Card(Card::suit::spade, Card::value::nine, 0, 0));
}

void Dealer::Deal_River(Table& t) {
	//t.receive_River(this->Pop_Card());
	t.receive_River(Card(Card::suit::spade, Card::value::eight, 0, 0));
}



