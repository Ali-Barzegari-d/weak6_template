#pragma once
#include <string>
#include <vector>
#include <optional>

struct Person {
    std::string name;

    Person(std::string n);
    Person(const Person&) = delete; // non-copyable
    Person(Person&&) noexcept = default; 
    Person& operator=(Person&&) noexcept = default;

    // rename_strong: if construction of new name fails, object remains unchanged
    void rename_strong(const std::string& new_name);
};

class PersonDirectory {
    std::vector<Person> people;
public:
    void add(Person p);
    bool removeByName(const std::string& n);
    std::optional<std::string> findByName(const std::string& n) const;

    // bulkRename: strong guarantee - if one rename fails, no one is changed
    void bulkRename(const std::string& suffix);
};
