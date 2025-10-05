#include "parse.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto maybe = to_int_status("123");
    assert(maybe && *maybe == 123);
    assert(to_int_exception("0") == 0);

    auto none = to_int_status("12x");
    assert(!none);

    bool threw = false;
    try {
        to_int_exception("abc");
    } catch (const std::invalid_argument&) { threw = true; }
    assert(threw);

    auto neg = to_int_status("-42");
    assert(neg && *neg == -42);

    auto big = to_int_status("999999999999999999999");
    assert(!big);

    std::cout << "parse tests passed\n";
    return 0;
}
