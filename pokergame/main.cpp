#include <iostream>
#include <vector>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include "player.h"
#include <vector>
#include "Deck.h"


using namespace std;
using namespace Graph_lib;


int main() {
	Deck d;
	//cout << d.ret_index(Card::suit::diamond, Card::value::eight);
	//Simple_window win(Point(0,0), 1920, 1080, "No Limit Hold-em");
	//win.wait_for_button();
	
	d.print_deck(cout);

	return 0;
}