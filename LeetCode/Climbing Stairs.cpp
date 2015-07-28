#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
class Solution {
public:
    int climbStairs(int n) {
        int *rs = new int[n + 1];
    memset(rs , 0 , sizeof(int) * (n + 1));
    rs[0] = 1;
    if(n > 0)
        rs[1] = 1;
    for(int i = 2; i < n + 1; i++)
    {
        rs[i] = rs[i - 2] + rs[i - 1];
    }
    return rs[n];

    }
};
