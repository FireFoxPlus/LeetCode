#include <vector>
#include <string>
using namespace std;
class Solution {
public:

void generateRackets(vector<string> &rs , int total , int left , int right , string tmpRs)
{
    if(left == total && right == total)
    {
        rs.push_back(tmpRs);
        return;
    }
    if(left < total)
    {
        string tmp = tmpRs + "(";
        generateRackets(rs , total , left + 1 , right , tmp);
    }
    if(left > right && right < total)
    {
        string tmp = tmpRs +  ")";
        generateRackets(rs , total , left , right + 1 , tmp);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> rs;
    string tmpRs;
    generateRackets(rs , n , 0 , 0 , tmpRs);
    return rs;
}
};
