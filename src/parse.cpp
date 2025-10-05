#include "parse.hpp"
#include <charconv>

std::optional<int> to_int_status(const std::string& s) {
    int value = 0;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    if (ec == std::errc() && ptr == s.data() + s.size()) {
        return value;
    }
    return std::nullopt;
}

int to_int_exception(const std::string& s) {
    if (auto v = to_int_status(s)) {
        return *v;
    }
    throw std::invalid_argument("to_int_exception: invalid integer: " + s);
}
