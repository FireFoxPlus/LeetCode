#include <stdlib.h>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
    int sign = 1;
    if(x < 0)
        sign = -1;
    x = abs(x);
    long long rs = 0;
    while(x != 0)
    {
        rs = rs * 10 + x % 10;
        if(rs > INT_MAX || rs < INT_MIN)
            return 0;
        x /= 10;
    }
    return rs * sign;
    }
};
