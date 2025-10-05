#pragma once
#include <string>
#include <vector>
#include <optional>

// Simple Person type: moveable, non-copyable
struct Person {
    std::string name;

    explicit Person(std::string n);

    Person(const Person&) = delete;
    Person(Person&&) noexcept = default;
    Person& operator=(Person&&) noexcept = default;

    // rename_strong: strong guarantee — if helper throws, name unchanged
    void rename_strong(const std::string& new_name);

    // Helper: may throw for certain names (used to simulate failures in tests).
    static std::string make_name_or_throw(const std::string& s);
};

class PersonDirectory {
    std::vector<Person> people;
public:
    void add(Person p);
    bool removeByName(const std::string& n);
    std::optional<std::string> findByName(const std::string& n) const;

    // bulkRename: strong guarantee - either all renamed, or no change.
    void bulkRename(const std::string& suffix);
};
