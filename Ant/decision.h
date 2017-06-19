#ifndef DECISION_H
#define DECISION_H

#include "utilities.h"

class Decision {
public:
    Decision();
    Decision(Action, int);
public:
    Action action;
    int nextStateNumber;
};

#endif // DECISION_H
