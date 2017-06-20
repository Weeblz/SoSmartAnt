#ifndef DECISION_H
#define DECISION_H

#include "utilities.h"

class Decision {
public:
    Decision();
    Decision(Action, int);
    bool operator==(const Decision&) const;
public:
    Action action;
    int nextStateNumber;
};

#endif // DECISION_H
