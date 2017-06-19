#ifndef STATE_H
#define STATE_H

#include "decision.h"

class State {
private:
    Decision canSeeApple;
    Decision canSeeNoApple;
public:
    State(Desidion, Desidion);
    State();
private:
    int makeDecision(bool, Action);
};

#endif // STATE_H
