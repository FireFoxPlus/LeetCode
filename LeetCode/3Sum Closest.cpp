#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
class Solution {
public:

void twoSum(vector<int> num , int index , int *rs , int *minGap, int target)
{
    int start = index + 1 , ends = num.size() - 1;
    int tmpRs;
    while(start < ends)
    {
        tmpRs = num[index] + num[start] + num[ends] - target;
        if(abs(tmpRs) < *minGap)
        {
            *minGap = abs(tmpRs);
            *rs = num[index] + num[start] + num[ends];
        }
        if(tmpRs > 0)
            ends--;
        else start++;

    }
}

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin() , nums.end());
    int Rs = 0 , minGap;
    for(int i = 0; i < nums.size(); i++)
        twoSum(nums , i , &Rs , &minGap , target);
    return Rs;
}
};
