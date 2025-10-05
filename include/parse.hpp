#pragma once
#include <optional>
#include <string>
#include <stdexcept>

std::optional<int> to_int_status(const std::string &s);
int to_int_exception(const std::string &s);
