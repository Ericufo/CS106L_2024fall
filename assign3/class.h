/*
What i want to implement in this assignment is to mock the game 
of hearthstone, and implement the basic structure of the game.
*/

#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <map>
#include <vector>

class MinionCard; // Forward declaration to avoid circular reference

// Trait base class for all mechanisms
class Trait {
public:
    virtual void activate(MinionCard& card) = 0;
    virtual ~Trait() = default; // Ensure proper cleanup for derived classes
};

// MinionCard class representing a minion card
class MinionCard {
private:
    std::string name;
    int cost;
    int attack;
    int health;
        
    std::map<std::string, int> states;
    std::vector<Trait*> traits;

public:
    MinionCard(std::string, int cost, int attack, int health);

    std::string getName() const;
    int getCost() const;
    int getAttack() const;
    int getHealth() const;

    void setName(std::string);
    void setCost(int);
    void setAttack(int);
    void setHealth(int);

    void addTrait(Trait* trait);
    void activateTraits();

    void setState(const std::string& key, int value);
    int getState(const std::string& key) const;

    void printInfo() const;

    void attackMinion(MinionCard& card);

    ~MinionCard();

};

// TauntTrait representing the Taunt mechanism
class TauntTrait : public Trait {
public:
    void activate(MinionCard& card) override;
};

#endif // CLASS_H