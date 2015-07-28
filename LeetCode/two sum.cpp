#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> m;
    vector<int> rs;
    for(int i = 0; i < nums.size(); i++)
    {
        if(m.count(nums[i]) == 0)
            m[target - nums[i]] = i;
        else
        {
            rs.push_back(m[nums[i]] + 1);
            rs.push_back(i + 1);
            break;
        }
    }
    return rs;
    }
};
