#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {

    set<int> records;
    while(n != 1)
    {
        if(records.count(n) != 0)
            return false;
         records.insert(n);
        int tmp = 0;
        while(n != 0)
        {
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = tmp;
    }
    return true;
    }
};
