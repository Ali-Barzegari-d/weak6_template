#include "iterable_processor.hpp"

// helper: get current active vector (owned or borrowed)
const std::vector<int>& IterableProcessor::current() const {
    if (owned) return *owned;
    if (borrowed) return *borrowed;
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

// Return const_iterators in all cases (safe for both owned & borrowed)
IterableProcessor::const_iterator IterableProcessor::begin() const {
    return current().cbegin();
}

IterableProcessor::const_iterator IterableProcessor::end() const {
    return current().cend();
}

IterableProcessor::const_iterator IterableProcessor::begin() {
    return current().cbegin();
}

IterableProcessor::const_iterator IterableProcessor::end() {
    return current().cend();
}

std::vector<int> IterableProcessor::process(std::function<int(int)> func) const {
    const auto& src = current();
    std::vector<int> result;
    result.reserve(src.size());
    for (int v : src) result.push_back(func(v));
    return result;
}
