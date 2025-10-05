#include "ranges_pipeline.hpp"
#include <ranges>
#include <vector>
#include <algorithm>

std::vector<int> top_unique_sorted_square_odds(const std::vector<int>& src, std::size_t n) {
    // TODO: build a ranges pipeline:
    //   1. filter odd numbers
    //   2. transform -> square
    // collect into a temporary vector

    std::vector<int> tmp;
    // TODO: copy elements from pipeline into tmp

    // TODO: sort tmp
    // TODO: remove duplicates (unique/erase idiom)

    // TODO: take first n elements from tmp and put into result
    std::vector<int> result;
    return result;
}
