#ifndef TABLE_H
#define TABLE_H

//using Player = Table::Player;

enum class Player {
    kNoPlayer = 0,
    kPlayerOne = 1,
    kPlayerTwo = 2,
};

class Table {
public:

    static constexpr int kDefaultDimension = 3;
    static constexpr int kDefaultColorOne = 100;
    static constexpr int kDefaultColorTwo = 200;

    Table();
    Table(int xBound, int yBound);
    Table(int xBound, int yBound, int colorOne, int colorTwo);
    virtual ~Table();

    void clear();

    void setMove(int x, int y, Player player);
    Player getMove(int x, int y);

    int getColor(Player player) const;

    int getXBound() const {
        return xBound_;
    }

    int getYBound() const {
        return yBound_;
    }

private:
    Player *table_;
    int xBound_;
    int yBound_;
    int colorOne_;
    int colorTwo_;

    void init(int xBound = kDefaultDimension,
              int yBound = kDefaultDimension,
              int colorOne = kDefaultColorOne,
              int colorTwo = kDefaultColorTwo);
    int getIdx(int x, int y);

    void setXBound(int x) {
        xBound_ = x;
    }

    void setYBound(int y) {
        yBound_ = y;
    }

    void setColorOne(int c1) {
        colorOne_ = c1;
    }

    void setColorTwo(int c2) {
        colorTwo_ = c2;
    }
};

#endif
