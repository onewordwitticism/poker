#include "Table.h"
#include "Graph.h"

const int MAGIC_STRING_OFFSET = 18;
const int MAGIC_STRING_OFFSET2 = 2;

void Table::receive_Flop(Card k) {
        Table::receive_Card(k);
}

void Table::receive_Turn(Card k) {
    this->Turn = new Card(k.ret_suit(), k.ret_value(), k.ret_in(), k.ret_pos());
}

void Table::receive_River(Card k) {
    this->River = new Card(k.ret_suit(), k.ret_value(), k.ret_in(), k.ret_pos());
}

//--------------------------------------------------------
void Table::draw_flop(Simple_window& w) {
    for (int i = 0; i < 3; i++) {
        int width = this->dim.width(); int height = this->dim.height();
        Point k = this->leftcorner;
        
        int leftcorner_x = k.x + 0.5 * width + (i * 100) - 240;
        int leftcorner_y = k.y + height - 150;
        Point temp(leftcorner_x, leftcorner_y);

        Cards[i]->define_card_edges(Point(leftcorner_x, leftcorner_y));
        string s = Cards[i]->ret_suitstring() + Cards[i]->ret_valuestring();
        Cards[i]->set_color(Color::dark_cyan);
        Cards[i]->set_text(Point(temp.x + MAGIC_STRING_OFFSET2, temp.y + MAGIC_STRING_OFFSET), s);

        w.attach(ret_cards(i));
    }
}

void Table::draw_turn(Simple_window& w) {
    int width = this->dim.width(); int height = this->dim.height();
    Point k = this->leftcorner;

    int leftcorner_x = k.x + 0.5 * width + (3 * 100) - 240;
    int leftcorner_y = k.y + height - 150;
    Point temp(leftcorner_x, leftcorner_y);

    Turn->define_card_edges(Point(leftcorner_x, leftcorner_y));
    string s = Turn->ret_suitstring() + Turn->ret_valuestring();
    Turn->set_color(Color::dark_cyan);
    Turn->set_text(Point(temp.x + MAGIC_STRING_OFFSET2, temp.y + MAGIC_STRING_OFFSET), s);

    w.attach(*Turn);
}

void Table::draw_river(Simple_window& w) {
    int width = this->dim.width(); int height = this->dim.height();
    Point k = this->leftcorner;

    int leftcorner_x = k.x + 0.5 * width + (4 * 100) - 240;
    int leftcorner_y = k.y + height - 150;

    River->define_card_edges(Point(leftcorner_x, leftcorner_y));
    River->set_color(Color::dark_cyan);
    Point temp(leftcorner_x, leftcorner_y);
    string s = River->ret_suitstring() + River->ret_valuestring();
    River->set_text(Point(temp.x + MAGIC_STRING_OFFSET2, temp.y + MAGIC_STRING_OFFSET), s);

    w.attach(*River);
}
//--------------------------------------------------------

void Table::print_playercards() {
    for (int i = 0; i < p_list.size(); i++) {
        p_list[i]->print_cards();
    }
}

void Table::draw_players() const {
    for (int i = 0; i < p_list.size(); i++) {
        p_list[i]->def_player_cards();
    }
}

void Table::draw_lines() const {
    dim.draw_lines();
}

void Table::setplayer_color(Color k) {
    for (int i = 0; i < p_list.size(); i++) {
        p_list[i]->setplayer_textcolor(k);
    }
}

void Table::setplayer_cardcolor(Color k) {
    for (int i = 0; i < p_list.size(); i++) {
        p_list[i]->setplayer_cardcolor(k);
    }
}

void Table::attache(Simple_window& w) {
    for (int i = 0; i < p_list.size(); i++) {
        w.attach(p_list[i]->ret_playername());
        for (int j = 0; j < 2; j++) {
            w.attach(p_list[i]->ret_card(j));
        }
    }
}

vector <Card*> Table::ret_all_cards() {
    vector <Card*> k;
    for (int i = 0; i < 3; i++) {
        k.push_back(Cards[i]);
    }

    k.push_back(Turn);
    k.push_back(River);
    return k;
}
