#include "decision.h"

Decision::Decision() : action(IDLE), nextStateNumber(0) {}
Decision::Decision(Action _action, int _nextStateNumber) : action(_action), nextStateNumber(_nextStateNumber) {}
