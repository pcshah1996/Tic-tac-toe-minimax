#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"
#include <string>

class View {
public:
    View();
    virtual ~View();

    void start();
    void command();
    void draw();

    int getX() const {
        return x_;
    }

    int getY() const {
        return y_;
    }

private:
    int x_;
    int y_;
    int c_x_;
    int c_y_;
    Controller* control_;

    void updateCenter();
    void drawGrid(int x, int y);

    void setX(int x) {
        x_ = x;
    }

    void setY(int y) {
        y_ = y;
    }

    void end();
};

#endif
