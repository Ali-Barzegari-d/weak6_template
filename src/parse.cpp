#include "parse.hpp"
#include <charconv>

std::optional<int> to_int_status(const std::string& s) {
    // TODO: implement parsing, return std::nullopt on failure
    return std::nullopt; 
}

int to_int_exception(const std::string& s) {
    // TODO: call to_int_status, throw std::invalid_argument on failure
    return 0; 
}
