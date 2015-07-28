#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
   void getCombination(vector<vector<int> > &rs , vector<int> candidates , vector<int> tmpRs , int index , int target)
{
    if(target == 0)
    {
        rs.push_back(tmpRs);
        return;
    }
    if(target < 0)
        return;
    for(int i = index + 1; i < candidates.size(); i++)
    {
        if(i != index + 1 && candidates[i] == candidates[i - 1])
            continue;
        tmpRs.push_back(candidates[i]);
        getCombination(rs , candidates , tmpRs  , i , target - candidates[i]);
        tmpRs.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> num , int target)
{
    vector<vector<int> > rs;
    if(num.size() == 0)
        return rs;
    sort(num.begin() , num.end());
    vector<int> tmpRs;
    getCombination(rs , num , tmpRs , -1 , target);
    return rs;
}
};
