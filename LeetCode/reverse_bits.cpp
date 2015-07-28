#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
            int rs = 0x00000000 , mask = 0x00000001;
    for(int i = 0; i < 32; i++)
    {
        int tmp = mask & n;
        if(tmp != 0)
            tmp = 1;
        tmp = tmp << (31 - i);
        rs |= tmp;
        mask <<= 1;
    }
    return rs;

    }
};
