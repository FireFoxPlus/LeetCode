
class Solution {
public:
    int trailingZeroes(int n) {
            int counts = 0;
    while(n != 0)
    {
        counts += n / 5;
        n /= 5;
    }
    return counts;
    }
};
