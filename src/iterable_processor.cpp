#include "iterable_processor.hpp"
#include <stdexcept>

const std::vector<int>& IterableProcessor::current() const {
    if (owned) return *owned;
    if (borrowed) return *borrowed;
    throw std::runtime_error("IterableProcessor: no data set");
}

void IterableProcessor::setBorrowed(const std::vector<int>& ref) {
    // TODO: assign borrowed pointer, reset owned
}

void IterableProcessor::setOwned(std::vector<int> data) {
    // TODO: move data into owned, reset borrowed
}

auto IterableProcessor::begin() {
    // TODO: return iterator depending on whether owned or borrowed is active
    return owned ? owned->begin() : borrowed->begin();
}

auto IterableProcessor::end() {
    // TODO: return iterator depending on state
    return owned ? owned->end() : borrowed->end();
}

auto IterableProcessor::begin() const {
    // TODO
    return owned ? owned->begin() : borrowed->begin();
}

auto IterableProcessor::end() const {
    // TODO
    return owned ? owned->end() : borrowed->end();
}

std::vector<int> IterableProcessor::process(std::function<int(int)> func) const {
    // TODO: iterate through elements, apply func, collect into result
    return {};
}
