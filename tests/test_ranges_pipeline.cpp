#include "ranges_pipeline.hpp"
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> s{1,2,3,4,5,6,7,3,5,1};

    auto r = top_unique_sorted_square_odds(s, 3);
    // odds: {1,3,5,7,3,5,1} -> squares {1,9,25,49,9,25,1}
    // unique + sort -> {1,9,25,49}
    // take 3 -> {1,9,25}
    assert(r.size() == 3);
    assert(r[0]==1 && r[1]==9 && r[2]==25);

    auto r2 = top_unique_sorted_square_odds(s, 10);
    // should return all unique sorted squares: {1,9,25,49}
    assert(r2.size() == 4);
    assert(r2[3]==49);

    std::cout << "ranges_pipeline tests passed\n";
    return 0;
}
