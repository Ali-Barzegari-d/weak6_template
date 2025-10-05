#pragma once
#include <vector>
#include <functional>
#include <optional>
#include <stdexcept>

class IterableProcessor {
    const std::vector<int>* borrowed = nullptr;
    std::optional<std::vector<int>> owned;

public:
    IterableProcessor() = default;

    // Borrowing: does not take ownership
    void setBorrowed(const std::vector<int>& ref);

    // Owning: takes ownership by moving data
    void setOwned(std::vector<int> data);

    // Iterators (we return const_iterator so both borrowed/owned work)
    using const_iterator = std::vector<int>::const_iterator;

    const_iterator begin() const;
    const_iterator end() const;

    // Non-const overloads return const_iterators as well (read-only iteration)
    const_iterator begin();
    const_iterator end();

    // Process all elements with a provided function (strategy)
    std::vector<int> process(std::function<int(int)> func) const;

private:
    const std::vector<int>& current() const; // helper
};
