#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rs = {-1 , -1};
    if(nums.size() == 0)
        return rs;
    if(nums.size() == 1)
    {
        if(nums[0] != target)
            return rs;
        else
        {
            rs.clear();
            rs.push_back(0);
            rs.push_back(0);
            return rs;
        }
    }
    int index1 , index2;
    int start = 0 , ends = nums.size() - 1;
    int mid = (start + ends) / 2;
    while(start < ends)
    {
        if(start + 1 == ends)
            break;
        if(nums[mid] < target)
            start = mid;
        else
            ends = mid;
        mid = (start + ends) / 2;
    }
    index1 = start;

    start = 0 , ends = nums.size() - 1;
    mid = (start + ends) / 2;
    while(start < ends)
    {
        if(start + 1 == ends)
            break;
        if(nums[mid] <= target)
            start = mid;
        else
            ends = mid;
        mid = (start + ends) / 2;
    }
    index2 = ends;
    rs.clear();
    //left
    if(nums[index1] == target)
        rs.push_back(index1);
    else
    {
        if(nums[index1 + 1] == target)
            rs.push_back(index1 + 1);
        else
            rs.push_back(-1);
    }

    //right
    if(nums[index2] == target)
        rs.push_back(index2);
    else
    {
        if(nums[index2 - 1] == target)
            rs.push_back(index2 - 1);
        else
            rs.push_back(-1);
    }
    return rs;
    }
};
