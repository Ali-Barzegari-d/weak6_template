#include "iterable_processor.hpp"
#include <stdexcept>

// helper: get current active vector (owned or borrowed)
const std::vector<int>& IterableProcessor::current() const {
    if (owned) return *owned;
    if (borrowed) return *borrowed;
    throw std::runtime_error("IterableProcessor: no data set");
}

std::vector<int>& IterableProcessor::current() {
    if (owned) return *owned;
    if (borrowed) throw std::runtime_error("Cannot modify borrowed data");
    throw std::runtime_error("IterableProcessor: no data set");
}

void IterableProcessor::setBorrowed(const std::vector<int>& ref) {
    borrowed = &ref;
    owned.reset();
}

void IterableProcessor::setOwned(std::vector<int> data) {
    owned = std::move(data);
    borrowed = nullptr;
}

auto IterableProcessor::begin() {
    return current().begin();
}

auto IterableProcessor::end() {
    return current().end();
}

auto IterableProcessor::begin() const {
    return current().begin();
}

auto IterableProcessor::end() const {
    return current().end();
}

std::vector<int> IterableProcessor::process(std::function<int(int)> func) const {
    std::vector<int> result;
    result.reserve(current().size());
    for (int v : current()) {
        result.push_back(func(v));
    }
    return result;
}
