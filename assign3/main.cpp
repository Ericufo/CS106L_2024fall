/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
    // Create a taunt minion
    MinionCard* tauntMinion = new MinionCard("Ironfur Grizzly", 3, 3, 3);
    tauntMinion->addTrait(new TauntTrait()); // Add Taunt mechanism

    // Activate traits and print info
    tauntMinion->activateTraits();
    tauntMinion->printInfo();

    // Create another minion and simulate attack
    MinionCard* otherMinion = new MinionCard("River Crocolisk", 2, 2, 3);
    otherMinion->printInfo();
    tauntMinion->attackMinion(*otherMinion);

    // Clean up
    delete tauntMinion;
    delete otherMinion;

    return 0;

  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"