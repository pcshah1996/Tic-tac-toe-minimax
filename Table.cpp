#include "Table.h"

Table::Table() {
    init();
}

Table::Table(int x, int y) {
    init(x, y);
}

Table::Table(int x, int y, int c1, int c2) {
    init(x, y, c1, c2);
}

Table::~Table() {
    delete [] table_;
}
void Table::init(int x, int y, int c1, int c2) {
    setXBound(x);
    setYBound(y);
    setColorOne(c1);
    setColorTwo(c2);

    table_ = new Player[x * y];
    clear();
}

int Table::getIdx(int x, int y) {
    return x * xBound_ + y;
}

int Table::getColor(Player player) const {
    switch(player) {
        case Player::kNoPlayer:
            return 0;
        case Player::kPlayerOne:
            return colorOne_;
        case Player::kPlayerTwo:
            return colorTwo_;
    }
}

void Table::clear() {
    int max =  xBound_ * yBound_;
    for (int i = 0; i < max; i++) {
        table_[i] = Player::kNoPlayer;
    }
}

Player Table::getMove(int x, int y) {
    return table_[getIdx(x,y)];
}

void Table::setMove(int x, int y, Player p) {
    table_[getIdx(x, y)] = p;
}
