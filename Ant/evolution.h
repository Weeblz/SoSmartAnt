#ifndef EVOLUTION_H
#define EVOLUTION_H
#include <thread>
#include <mutex>
#include <vector>
#include <utility>
#include "state.h"
#include "field.h"
#include "ant.h"

class Evolution {
private:
    std::recursive_mutex lock;
    std::vector<std::thread> threads;                               // vector containing threads of evolution

    std::vector<std::pair<std::vector<State>, int>> generation;     // current state of ant "colony" (or generation, whatever). Contains behavior rules and it's efficiency.
    std::vector<State> bestBehavior;                                // set of dicision making rules for the most adapted ant.

    bool evolved;                                                   // last generation is reached or ant evolved and able to eat all apples on the gaming grid.
    int maxFitness;                                                 // estimation of how good is the most adapted ant in eating apples.
    int currentGeneration;                                          // how many generations of ants have changed.

    Field* gamingGrid;                                              //gaming grid where ants are evolving.
public:
    Evolution();

    std::vector<State> evolve();                                    // begin the evolving process, mutating and crossovering generations of ants.
                                                                    // @return: set of dicision making rules for the most adapted ant.
private:
    void populate();                                                // create generation number 0 with random set of rules.
    void changeGeneration();                                        // change generation with some mutations, crossovers and selection.
    void mutate(std::pair<std::vector<State>, int>&);               // mutate certain ant in one of 3 diffenrent ways.
    void mutateAll();                                               // mutate every ant with predefined probability.
    void crossover(const std::pair<std::vector<State>, int>&,
                   const std::pair<std::vector<State>, int>&, int); // crossover gets 2 children from 2 parents.
    void crossoverAll();                                            // crossovers for everyone!
    void select();                                                  // calculates behavior efficiency of every single ant in current generation and sorts it. The next call of
                                                                    // crossoverAll() will replace the least efficient half of generation with children of the most efficient ones.
    void recalculateEfficiency();                                   // tests current generation and evaluates efficiency of each ant.
    void getEfficiency(std::pair<std::vector<State>, int>&);        // test and updates efficiency of choosen ant.
};

#endif // EVOLUTION_H
