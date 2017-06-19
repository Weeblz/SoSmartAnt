#include "evolution.h"
#include "utilities.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

bool comparator(const std::pair<std::vector<State>, int>&a, const std::pair<std::vector<State>, int>&b) {
    return a.second>b.second;
}

Evolution::Evolution() : currentGeneration(0) {
    srand(time(NULL));
    generation.reserve(GENERATION_SIZE * 2);
}

std::vector<State> Evolution::evolve() {
    populate();
    while (!evolved) changeGeneration();
    return bestBehavior;
}

void Evolution::populate() {
    std::vector<State> temp(STATE_COUNT);
    for (int i = 0; i < 2 * GENERATION_SIZE; i++){
        for (int j = 0; j < temp.size(); j++){
            Decision canSeeFood((Action)(rand() % 3), rand() % STATE_COUNT);
            Decision canSeeNoFood((Action)(rand() % 3), rand() % STATE_COUNT);
            temp[j] = State(canSeeFood, canSeeNoFood);
        }
        generation.push_back(std::make_pair(temp, -1));
    }
}

void Evolution::changeGeneration() {
    select();
    crossoverAll();
    evolved ? : currentGeneration++;
}

void Evolution::mutate(std::pair<std::vector<State>, int>& mutant) {
    mutant.second = -1;
    int mutation = (rand() % 3) + 1;
    int randomState = rand() % mutant.first.size();
    bool randomTranslation = rand() % 2;

    switch (mutation){
        case 1: {
            Action randomAction = (Action)(rand() % 3);
            if (randomTranslation)
                mutant.first[randomState].canSeeApple.action = randomAction;
            else
                mutant.first[randomState].canSeeNoApple.action = randomAction;
            break;
        }
        case 2: {
            int randomArrState = rand() % mutant.first.size();
            if (randomTranslation)
                mutant.first[randomState].canSeeApple.nextStateNumber = randomArrState;
            else
                mutant.first[randomState].canSeeNoApple.nextStateNumber = randomArrState;
            break;
        }
        case 3: {
            Decision temp = mutant.first[randomState].canSeeApple;
            mutant.first[randomState].canSeeApple = mutant.first[randomState].canSeeNoApple;
            mutant.first[randomState].canSeeNoApple = temp;
            break;
         }
    }
}


void Evolution::mutateAll() {
    for (int i = 0; i < generation.size(); i++){
        if (rand() % 100 < MUTATION_PROBABILITY) mutate(generation[i]);
    }
}

void Evolution::crossover(const std::pair<std::vector<State>, int>& parent1, const std::pair<std::vector<State>, int>& parent2, int index) {
    std::vector<State> child1(STATE_COUNT);
    std::vector<State> child2(STATE_COUNT);
    int randomDecisionIndex;
    State firstChildState, secondChildState;
    std::vector<Decision> pool;

    for (int i = 0; i < STATE_COUNT; i++){
        pool.clear();
        pool.push_back(parent1.first[i].canSeeApple);
        pool.push_back(parent1.first[i].canSeeNoApple);
        pool.push_back(parent2.first[i].canSeeApple);
        pool.push_back(parent2.first[i].canSeeNoApple);

        randomDecisionIndex = rand() % pool.size();
        firstChildState.canSeeApple = pool[randomDecisionIndex];
        pool.erase(pool.begin() + randomDecisionIndex);

        randomDecisionIndex = rand() % pool.size();
        firstChildState.canSeeNoApple = pool[randomDecisionIndex];
        pool.erase(pool.begin() + randomDecisionIndex);

        randomDecisionIndex = rand() % pool.size();
        secondChildState.canSeeApple = pool[randomDecisionIndex];
        pool.erase(pool.begin() + randomDecisionIndex);

        randomDecisionIndex = rand() % pool.size();
        secondChildState.canSeeNoApple = pool[randomDecisionIndex];

        child1[i] = firstChildState;
        child2[i] = secondChildState;
    }

    //child1.currentState = child1.states.front();
    //child2.currentState = child2.states.front();

    lock.lock();
    (generation[index].first) = child1;
    (generation[index + 1].first) = child2;
    lock.unlock();
}

void Evolution::crossoverAll() {
    std::vector<int> parentsIndexes;
    parentsIndexes.reserve(generation.size() / 2);
    int parent1, parent2;
    int i = 0;
    for (; i < generation.size() / 2; i++) parentsIndexes.push_back(i);

    while (!parentsIndexes.empty()){
        parent1 = rand() % parentsIndexes.size();
        parentsIndexes.erase(parentsIndexes.begin() + parent1);
        if (parentsIndexes.empty()) break;

        parent2 = rand() % parentsIndexes.size();
        parentsIndexes.erase(parentsIndexes.begin() + parent2);

        crossover(generation[parent1], generation[parent2], i);
        i += 2;
    }
}

void Evolution::select() {
    recalculateEfficiency();
    std::sort(generation.begin(), generation.end(), comparator);

    if (generation.front().second >= APPLES_COUNT || currentGeneration >= NUMBER_OF_GENERATIONS){
        bestBehavior = generation.front().first;
        evolved = true;
        return;
    }

    maxFitness = generation.front().second;
}

void Evolution::recalculateEfficiency() {
    for (int i = 0; i < generation.size(); i++){
        if (generation[i].second < 0){
            //fitness(currentGeneration[i]);
            threads.push_back(std::thread([=] {getEfficiency(generation[i]);}));
        }
    }
    for (unsigned int i = 0; i < threads.size(); i++) threads[i].join();
    threads.clear();
}

void Evolution::getEfficiency(std::pair<std::vector<State>, int>& ant) {
        lock.lock();
        Field testingField(Position(0,0));
        Ant subject(Position(0,0), ant.first, &testingField);
        lock.unlock();
        int steps = 0;
        for (;steps < 200; steps++){
            if (subject.getApplesEaten() == APPLES_COUNT) break;
            subject.move();
        }
        ant.second = subject.getApplesEaten() + (200 - steps);
}
