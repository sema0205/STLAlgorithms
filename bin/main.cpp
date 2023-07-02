#include <iostream>
#include <vector>
#include <list>

#include "../lib/stl-algorithms/algorithms.h"

using namespace algo;

int main() {

    // auto x = algo::xrange(1.5, 5.5);
    // std::vector<double> v{x.begin(), x.end()};

    // auto x = xrange(1.5, 5.5);
    // std::vector<double> v{x.begin(), x.end()}; // 1.5 2.5 3.5 4.5
    // for(auto k : v) {
    //     std::cout << k << " ";
    // }

    // auto k = algo::xrange(13);
    
    std::vector test = {6,7,5,6,5,3,2,27,6,36};

    std::cout << std::boolalpha << is_partitioned(test.begin(), test.end(), [](int value){return value > 3;}) << "\n";

    return 0;
}

