#include "person_directory.hpp"
#include <algorithm>
#include <stdexcept>

// --- Person implementation ---

Person::Person(std::string n) : name(std::move(n)) {}

// Example helper: simulate failure when resulting name equals "Fail!"
std::string Person::make_name_or_throw(const std::string& s) {
    if (s == "Fail!") {
        throw std::runtime_error("simulated name construction failure for: " + s);
    }
    return s;
}

void Person::rename_strong(const std::string& new_name) {
    // Strong guarantee: build new value first, then commit via swap.
    // If make_name_or_throw throws, `name` remains unchanged.
    std::string tmp = make_name_or_throw(new_name); // may throw
    name.swap(tmp); // commit (noexcept)
}

// --- PersonDirectory implementation ---

void PersonDirectory::add(Person p) {
    people.push_back(std::move(p));
}

bool PersonDirectory::removeByName(const std::string& n) {
    const auto old = people.size();
    people.erase(
        std::remove_if(people.begin(), people.end(),
                       [&n](const Person& p) { return p.name == n; }),
        people.end()
    );
    return people.size() != old;
}

std::optional<std::string> PersonDirectory::findByName(const std::string& n) const {
    auto it = std::find_if(people.begin(), people.end(),
                           [&n](const Person& p) { return p.name == n; });
    if (it != people.end()) return it->name; // copy name out
    return std::nullopt;
}

void PersonDirectory::bulkRename(const std::string& suffix) {
    // Strong guarantee: build a temporary vector of renamed Persons.
    // If any construction fails (make_name_or_throw throws), original 'people'
    // remains unchanged. On success, swap tmp into people.
    std::vector<Person> tmp;
    tmp.reserve(people.size());

    for (const auto& p : people) {
        // build candidate new name (may throw)
        std::string newName = Person::make_name_or_throw(p.name + suffix);
        // If we reach here, construction for this person succeeded;
        // make a Person with the new name and append to tmp.
        tmp.emplace_back(std::move(newName));
    }

    // Commit: all renames succeeded — do an efficient swap (noexcept)
    people.swap(tmp);
}
