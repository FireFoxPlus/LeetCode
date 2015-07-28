#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
    if(len == 1)
        return nums[0];
    int fMax = nums[len - 1] , gMax = nums[len - 1] , gMin = nums[len - 1];
    for(int i = nums.size() - 2; i >= 0; i--)
    {
        fMax = max(max(nums[i] , nums[i] * gMax) , max(nums[i] * gMin , fMax));
        int tmp = gMax;
        gMax = max(max(nums[i] , nums[i] * gMax) , nums[i] * gMin);
        gMin =  min(min(nums[i] , nums[i] * gMin) , nums[i] * tmp);
    }
    return fMax;
    }
};
