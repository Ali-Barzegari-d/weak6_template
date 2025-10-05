#include "ranges_pipeline.hpp"
#include <ranges>
#include <vector>
#include <algorithm>

std::vector<int> top_unique_sorted_square_odds(const std::vector<int>& src, std::size_t n) {
    // Step 1 + 2: filter odds and square them
    auto pipeline = src
        | std::views::filter([](int x){ return x % 2 != 0; })
        | std::views::transform([](int x){ return x * x; });

    // Step 3: collect into temporary vector
    std::vector<int> tmp;
    for (int x : pipeline) {
        tmp.push_back(x);
    }

    // Step 4: sort
    std::ranges::sort(tmp);

    // Step 5: remove duplicates
    auto it = std::ranges::unique(tmp);
    tmp.erase(it.begin(), it.end());

    // Step 6: take first n
    std::vector<int> result;
    for (std::size_t i = 0; i < n && i < tmp.size(); ++i) {
        result.push_back(tmp[i]);
    }

    return result;
}
