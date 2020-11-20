#pragma once
#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "Player.h"
#include "Simple_window.h"

struct Table : Shape {
    // table is setting the color for all shapes inside the thingo - very interesting.  Not necessarily the font size tho etc.
    Table(Point p, int width, int height, int num_playerss) : dim(p, width, height), leftcorner(p), num_players(num_playerss) { dim.set_color(Color::blue);
    // maybe the only thing i can do it to make p_list as shapes as well as cards then try to force them from a table member function to be a diff colour.
    // also try to make the Cards vector directly a diff colour from member functions in table here.
    }
    void add_player(Point p, string s) { p_list.push_back(new Player(1000, p, s)); }
    
    //game functions
    void receive_Card(Card k) { Cards.push_back(new Card(k.ret_suit(), k.ret_value(), k.ret_in(), k.ret_pos())); }
    void receive_Flop(Card k);
    void receive_Turn(Card k);
    void receive_River(Card k);
    
    //print and return
    void print_playercards();
    vector <Player*> ret_players() { return p_list; }
    Card& ret_cards(int i) { return *Cards[i]; }
    vector <Card*> ret_all_cards();
    int ret_num_players() { return num_players; }

    //Graphics/drawing/colors
    void attache(Simple_window& w);
    void draw_players() const;
    void draw_lines() const;
    void setplayer_color(Color k);
    void setplayer_cardcolor(Color k);
    void draw_flop(Simple_window& w);
    void draw_turn(Simple_window& w);
    void draw_river(Simple_window& w);
    Point& get_leftcorner() { return leftcorner; }
private:
    vector <Player*> p_list;
    vector <Card*> Cards;
    Card* Turn;
    Card* River;
    Graph_lib::Rectangle dim;
    Point leftcorner;
    int num_players;
};





