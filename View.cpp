#include "View.h"

#include <ncurses.h>
#include <iostream>

static const std::string kLoading = "Loading components...";
static constexpr int kLoadingOffset = 10;
static const std::string kHDiv = "--------+--------+--------";
static const std::string kVDiv = "        |        |        ";
static constexpr int kDivOffset = 12;


View::View(/*Controller control*/) {
    initscr();
    updateCenter();
    mvprintw(c_y_, c_x_ - kLoadingOffset, kLoading.c_str());
    refresh();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    ESCDELAY = 0;
    keypad(stdscr, true);

    //control_ = &control;
    // center of the board
    setX(1);
    setY(1);
}

View::~View() {
    //delete control_;
}

void View::updateCenter() {
    c_x_ = COLS / 2;
    c_y_ = LINES / 2;
}

void View::start() {
    while(1) {
        updateCenter();
        command();
        draw();
    }
}

void View::draw() {
    clear();
    drawGrid(c_x_, c_y_);
    mvprintw(10, 10, "%d %d", getX(), getY());
    mvprintw(getY(), getX(), ".");
    refresh();
}

void View::drawGrid(int x, int y) {

    mvprintw(y - 8, x - kDivOffset, kVDiv.c_str());
    mvprintw(y - 7, x - kDivOffset, kVDiv.c_str());
    mvprintw(y - 6, x - kDivOffset, kVDiv.c_str());
    mvprintw(y - 5, x - kDivOffset, kVDiv.c_str());
    mvprintw(y - 4, x - kDivOffset, kVDiv.c_str());

    mvprintw(y - 3, x - kDivOffset, kHDiv.c_str());

    mvprintw(y - 2, x - kDivOffset, kVDiv.c_str());
    mvprintw(y - 1, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 0, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 1, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 2, x - kDivOffset, kVDiv.c_str());

    mvprintw(y + 3, x - kDivOffset, kHDiv.c_str());

    mvprintw(y + 4, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 5, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 6, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 7, x - kDivOffset, kVDiv.c_str());
    mvprintw(y + 8, x - kDivOffset, kVDiv.c_str());
}

void View::command() {
    int cmd = getch();

    int dX = 0;
    int dY = 0;

    switch(cmd) {
    case KEY_LEFT:
        dX = -1;
        break;
    case KEY_RIGHT:
        dX = 1;
        break;
    case KEY_UP:
        dY = -1;
        break;
    case KEY_DOWN:
        dY = 1;
        break;
    case 10: // enter key
        // talk to controller
        break;
    case 27: // esc key
        end();
        break;
    }

    int tempX = getX() + dX;
    int tempY = getY() + dY;

    if (/*tempX < control_->getMaxX() &&*/ tempX >= 0) {
        setX(tempX);
    }
    if (/*tempY < control_->getMaxY() &&*/ tempY >= 0) {
        setY(tempY);
    }
}

void View::end() {
    mvprintw(10, c_x_ - 4,  "Goodbye!");
    refresh();
    getch();
    endwin();
    exit(0);
}
