#include "class.h"
#include <iostream>

// MinionCard implementation
MinionCard::MinionCard(std::string name, int cost, int attack, int health)
    : name(name), cost(cost), attack(attack), health(health) {}

std::string MinionCard::getName() const {
    return name;
}

int MinionCard::getCost() const {
    return cost;
}

int MinionCard::getAttack() const {
    return attack;
}

int MinionCard::getHealth() const {
    return health;
}

void MinionCard::setName(std::string name) {
    this->name = name;
}

void MinionCard::setCost(int cost) {
    this->cost = cost;
}

void MinionCard::setAttack(int attack) {
    this->attack = attack;
}

void MinionCard::setHealth(int health) {
    this->health = health;
}

void MinionCard::addTrait(Trait* trait) {
    traits.push_back(trait);
}

void MinionCard::activateTraits() {
    for (auto& trait : traits) {
        trait->activate(*this);
    }
}

void MinionCard::setState(const std::string& key, int value) {
    states[key] = value;
}

int MinionCard::getState(const std::string& key) const {
    auto it = states.find(key);
    return it != states.end() ? it->second : 0;
}


void MinionCard::printInfo() const {
    std::cout << "Minion: " << name
              << " (Mana Cost: " << cost
              << ", Attack: " << attack
              << ", Health: " << health << ")\n";

    for (const auto& state : states) {
        if (state.second > 0) {
            std::cout << " - " << state.first << ": " << state.second << std::endl;
        }
    }
}

void MinionCard::attackMinion(MinionCard& card) {
    std::cout << name << " attacks " << card.getName() << "!\n";
    card.setHealth(card.getHealth() - attack);
    setHealth(health - card.getAttack());

    if (card.getHealth() <= 0) {
        std::cout << card.getName() << " has died.\n";
    }
    if (health <= 0) {
        std::cout << name << " has died.\n";
    }
}

MinionCard::~MinionCard() {
    for (auto& trait : traits) {
        delete trait; // Clean up traits
    }
}

// TauntTrait implementation
void TauntTrait::activate(MinionCard& card) {
    card.setState("Taunt", 1); // Set the "Taunt" state
    std::cout << card.getName() << " now has Taunt!\n";
}