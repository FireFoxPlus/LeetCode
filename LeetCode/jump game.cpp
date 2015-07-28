#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int start = 0 , ends = 0;
    ends = nums[0];
    for(int i = 1; i <= ends && i < nums.size(); i++)
    {
        if(i + nums[i] > ends && nums[i] != 0)
            ends = i + nums[i];
    }
    if(ends >= nums.size() - 1)
        return true;
    return false;
    }
};
