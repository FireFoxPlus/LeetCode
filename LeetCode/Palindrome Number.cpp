
class Solution {
public:
    bool isPalindrome(int x) {
         if(x < 0)
        return false;
        long long tmp = 0 , src = x;
    while(x != 0)
    {
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return src == tmp;
    }
};
