#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Table.h"

class Controller {
public:
    Controller(){}
    virtual ~Controller(){}

    int getMaxX() {
        return max_x_;
    }

    int getMaxY() {
        return max_y_;
    }

    virtual void advance()=0;
    //virtual void

protected:
    int max_x_;
    int max_y_;
    Player current_;
    Table table_;

};

#endif
