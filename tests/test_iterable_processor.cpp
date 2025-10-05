#include "iterable_processor.hpp"
#include <cassert>
#include <iostream>

int square(int x) { return x * x; }

int main() {
    std::vector<int> ext = {1,2,3};

    IterableProcessor proc;
    proc.setBorrowed(ext);

    int sum = 0;
    for (int v : proc) sum += v;
    assert(sum == 6);

    auto squared = proc.process(square);
    assert((squared == std::vector<int>{1,4,9}));

    // test owned
    proc.setOwned(std::vector<int>{5,6,7});
    auto doubled = proc.process([](int x){ return x*2; });
    assert((doubled == std::vector<int>{10,12,14}));

    int sum2 = 0;
    for (int v : proc) sum2 += v;
    assert(sum2 == 18);

    std::cout << "iterable_processor tests passed\n";
    return 0;
}
