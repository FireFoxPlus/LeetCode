#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPail(string s)
{
    string copys = s;
    reverse(s.begin() , s.end());
    return copys == s;
}
void traceback(string s, vector<vector<string>> &ispal,vector<string> &tmpRs,
               int index)
{
   if(index >= s.length() - 1)
    {
        string tmp = s.substr(index , 1);
        if(tmp.length() != 0)
        {
            tmpRs.push_back(tmp);
            ispal.push_back(tmpRs);
            tmpRs.pop_back();
        }
        else
            ispal.push_back(tmpRs);
        return;
    }
    for(int j = index; j < s.length(); j++)
    {
        string tmp = s.substr(index , j - index + 1);
        if(isPail(tmp))
        {
            tmpRs.push_back(tmp);
            traceback(s , ispal , tmpRs , j + 1);
            tmpRs.pop_back();
        }

    }
}

    vector<vector<string>> partition(string s) {
        vector<vector<string> > rs;
      if(s.length() == 0)
        return rs;
          if(s.length() == 1)
    {
        vector<string> tmp;
        tmp.push_back(s);
        rs.push_back(tmp);
        return rs;
    }
    for(int i = 0; i < s.length(); i++)
    {
        vector<string> tmpRs;
        string tmp = s.substr(0 , i + 1);
        if(isPail(tmp))
        {
            tmpRs.push_back(tmp);
            traceback(s , rs , tmpRs , i + 1);
            tmpRs.pop_back();
        }
    }
    return rs;
    }
};
