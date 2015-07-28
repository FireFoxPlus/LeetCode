#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
            int counts = 0;
    while(n != 0)
    {
        counts++;
        n = n & (n - 1);
    }
    return counts;

    }
};
