#include "state.h"

State::State() {

}

State::State(Desision Apple, Desision NoApple) : canSeeApple(Apple), canSeeNoApple(NoApple) {}

int State::makeDecision(bool _canSeeApple, Action nextAction) {
    if(_canSeeApple) {
        nextAction = canSeeApple.action;
        return canSeeApple.nextStateNumber;
    }
    else {
        nextAction = canSeeNoApple.action;
        return canSeeNoApple.nextStateNumber;
    }
}
