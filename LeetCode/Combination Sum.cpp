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
    for(int i = index; i < candidates.size(); i++)
    {
        if(i != index && candidates[i] == candidates[i - 1])
            continue;
        tmpRs.push_back(candidates[i]);
        getCombination(rs , candidates , tmpRs  , i , target - candidates[i]);
        tmpRs.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates , int target)
{
    vector<vector<int> > rs;
    if(candidates.size() == 0)
        return rs;
    sort(candidates.begin() , candidates.end());
    vector<int> tmpRs;
    getCombination(rs , candidates , tmpRs , 0 , target);
    return rs;
}
};
