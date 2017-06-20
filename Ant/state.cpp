#include "state.h"

State::State() {}
State::State(Decision Apple, Decision NoApple) : canSeeApple(Apple), canSeeNoApple(NoApple) {}

int State::makeDecision(bool _canSeeApple, Action& nextAction) {
    if(_canSeeApple) {
        nextAction = canSeeApple.action;
        return canSeeApple.nextStateNumber;
    }
    else {
        nextAction = canSeeNoApple.action;
        return canSeeNoApple.nextStateNumber;
    }
}

bool State::operator==(const State& a) const {
    return (canSeeApple == a.canSeeApple) && (canSeeNoApple == a.canSeeNoApple);
}

