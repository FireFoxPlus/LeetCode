#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
 if(k == 0)
        return ;
    reverse(nums , nums + n);
    reverse(nums , nums + k % n);
    reverse(nums + k % n , nums + n);

    }
};
