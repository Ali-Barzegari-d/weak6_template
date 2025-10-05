#pragma once
#include <vector>
#include <functional>
#include <optional>

class IterableProcessor {
    const std::vector<int>* borrowed = nullptr;
    std::optional<std::vector<int>> owned;

public:
    IterableProcessor() = default;

    // Borrowing: does not take ownership
    void setBorrowed(const std::vector<int>& ref);

    // Owning: takes ownership by moving data
    void setOwned(std::vector<int> data);

    // Iterators (work for both owned and borrowed)
    auto begin();
    auto end();
    auto begin() const;
    auto end() const;

    // Process all elements with a provided function (strategy)
    std::vector<int> process(std::function<int(int)> func) const;
};
