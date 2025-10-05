#include "person_directory.hpp"
#include <cassert>
#include <iostream>

int main() {
    PersonDirectory dir;
    dir.add(Person("Alice"));
    dir.add(Person("Bob"));
    dir.add(Person("Eve"));

    // test find
    auto f = dir.findByName("Alice");
    assert(f && *f == "Alice");

    // test remove
    bool removed = dir.removeByName("Bob");
    assert(removed);
    assert(!dir.findByName("Bob"));

    // test rename strong
    Person p("X");
    p.rename_strong("Good");
    assert(p.name == "Good");

    // test bulkRename strong guarantee
    dir.add(Person("Fail")); 
    try {
        dir.bulkRename("!"); // suppose "Fail" + "!" triggers exception
    } catch (...) {}
    // directory should be unchanged if exception happened
    assert(dir.findByName("Alice"));

    std::cout << "person_directory tests passed\n";
    return 0;
}
