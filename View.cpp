#include "View.h"

#include <ncurses.h>

View::View(/*Controller control*/) {
    initscr();
    mvprintw(LINES/2, COLS/2 - 10, "Loading components...");
    refresh();
    getch();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    ESCDELAY = 0;
    keypad(stdscr, true);

    //control_ = &control;
    setX(0);
    setY(0);
}

View::~View() {
    //delete control_;
}

void View::start() {
    while(1) {
        draw();
        //command();
    }
}

void View::draw() {
    clear();
    mvprintw(0, 10, "Prateeeek");

    refresh();
}
