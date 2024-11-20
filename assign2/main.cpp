/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <random>
#include <algorithm>

#include "utils.h"

std::string kYourName = "Eric Ou";

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  std::unordered_set<std::string> applicants;
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
    return applicants;
  }
  std::string name;
  while(std::getline(ifs, name)) {
    applicants.insert(name);
  }
  return applicants;
}

std::string name_initials(const std::string& name) {
  std::string first_name;
  std::string last_name;
  std::stringstream ss(name);
  ss >> first_name >> last_name;
  return std::string(1, first_name[0]) + last_name[0];
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  std::string target = name_initials(name);
  std::queue<const std::string*> matches;
  auto b = students.begin();
  auto e = students.end();
  for (auto it = b; it != e; ++it) {
    auto elem = *it;
    if (name_initials(elem) == target) {
      matches.push(&(*it));
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  std::vector<const std::string*> random;
  while (!matches.empty()) {
    random.push_back(matches.front());
    matches.pop();
  }

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(random.begin(), random.end(), g);

  return *random[0];
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
