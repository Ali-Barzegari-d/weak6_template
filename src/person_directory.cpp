#include "person_directory.hpp"
#include <algorithm>
#include <stdexcept>

// --- Person ---

Person::Person(std::string n) : name(std::move(n)) {}

std::string Person::make_name_or_throw(const std::string& s) {
    if (s == "Fail!") {
        throw std::runtime_error("simulated name construction failure for: " + s);
    }
    return s;
}

void Person::rename_strong(const std::string& new_name) {
    // TODO: implement strong guarantee using temporary + swap
    
}

// --- PersonDirectory ---

void PersonDirectory::add(Person p) {
    // TODO: add person to people
}

bool PersonDirectory::removeByName(const std::string& n) {
    // TODO: erase-remove idiom, return true if someone removed
    return false;
}

std::optional<std::string> PersonDirectory::findByName(const std::string& n) const {
    // TODO: search in vector, return name if found, else nullopt
    return std::nullopt;
}

void PersonDirectory::bulkRename(const std::string& suffix) {
    // TODO: strong guarantee: 
    //   prepare temp copy of all renamed persons
    //   if all succeed, commit by swapping with people
}
