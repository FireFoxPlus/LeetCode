#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

void BackTrack(vector<vector<int> > &rs , vector<int> S , vector<int> tmpRs , int dep)
{
    if(dep == S.size())
    {
        sort(tmpRs.begin() , tmpRs.end());
        rs.push_back(tmpRs);
        return;
    }

    BackTrack(rs , S , tmpRs , dep + 1);

    tmpRs.push_back(S[dep]);
    BackTrack(rs , S , tmpRs , dep + 1);
}

vector<vector<int> > subsets(vector<int> &S)
{
    vector<vector<int> > rs;
    vector<int> tmpRs;
    BackTrack(rs , S , tmpRs , 0);
    return rs;
}
};
