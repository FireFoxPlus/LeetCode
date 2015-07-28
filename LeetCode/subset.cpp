#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:

void subSet(set<vector<int> > &rs , int startIndex , vector<int> tmpRs , vector<int> input)
{
    if(startIndex >= input.size())
    {
        sort(tmpRs.begin() , tmpRs.end());
        rs.insert(tmpRs);
        return;
    }
    for(int i = startIndex; i <= input.size(); i++)
    {
        if(i == input.size())
            subSet(rs , i + 1 , tmpRs , input);
        else
        {
            tmpRs.push_back(input[i]);
            subSet(rs , i + 1 , tmpRs , input);
            tmpRs.pop_back();
        }
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
    set<vector<int> > rs;
    vector<vector<int> > rsVec;
    rs.insert(vector<int>());
    if(S.empty())
    {
        rsVec.push_back(vector<int>());
        return rsVec;
    }
    vector<int>  tmpRs;
    subSet(rs , 0 , tmpRs , S);
    rsVec.insert(rsVec.end() , rs.begin() , rs.end());
    return rsVec;
}

};
