#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H

#include "Controller.h"

class HumanController : public Controller {

public:
    HumanController();
    virtual ~HumanController() {};
    void advance();

};

#endif
