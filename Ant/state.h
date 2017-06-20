#ifndef STATE_H
#define STATE_H

#include "decision.h"

class State {
public:
    State();
    State(Decision, Decision);

    int makeDecision(bool, Action&);
    bool operator==(const State&) const;
public:
    Decision canSeeApple;
    Decision canSeeNoApple;
};

#endif // STATE_H
