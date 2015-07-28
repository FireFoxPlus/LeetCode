#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
      int len = nums.size() - 1;
    if(nums[0] < nums[len])
        return nums[0];
    int start = 0 , ends = nums.size() - 1;
    int mid = (start + ends) / 2;
    while(start < ends)
    {
        if(nums[mid] >= nums[0] && nums[mid] >= nums[len])
        {
            if(mid != len && nums[mid] < nums[mid + 1])
                start =  mid + 1;
            else
                return nums[mid + 1];
        }
        else if(nums[mid] <= nums[len] && nums[mid] <= nums[0])
        {
            if(mid != 0 && nums[mid] > nums[mid - 1])
                ends = mid - 1;
            else
                return nums[mid];
        }

        mid = (start + ends) / 2;
    }
    return nums[start];

    }
};
