#pragma once
#include <string>
#include <vector>
#include <optional>

struct Person {
    std::string name;

    explicit Person(std::string n);

    Person(const Person&) = delete;
    Person(Person&&) noexcept = default;
    Person& operator=(Person&&) noexcept = default;

    void rename_strong(const std::string& new_name);

    static std::string make_name_or_throw(const std::string& s);
};

class PersonDirectory {
    std::vector<Person> people;
public:
    void add(Person p);
    bool removeByName(const std::string& n);
    std::optional<std::string> findByName(const std::string& n) const;

    void bulkRename(const std::string& suffix);
};