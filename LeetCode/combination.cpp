#include <vector>
using namespace std;
class Solution {
public:
   void getCombine(int n , int k , vector<vector<int> > &rs , vector<int> tmpRs , int dep)
{
    if(tmpRs.size() == k)
    {
        rs.push_back(tmpRs);
        return;
    }
    for(int i = dep;  i <= n; i++)
    {
        tmpRs.push_back(i);
        getCombine(n , k , rs , tmpRs , i + 1);
        tmpRs.pop_back();
    }
}

vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > rs;
    vector<int> tmpRs;
    getCombine(n , k , rs , tmpRs , 1);
    return rs;
}
};
