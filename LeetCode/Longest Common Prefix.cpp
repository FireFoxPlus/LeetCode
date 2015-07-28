#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rs;
           if(strs.size() == 0)
        return rs;
    rs = strs[0];
    for(int i = 1; i < strs.size(); i++)
    {
        string::iterator src , dst;
        for(src = rs.begin() , dst = strs[i].begin();
            src != rs.end() && dst != strs[i].end();
            src++ , dst++)
        {
            if(*src != *dst)
                break;
        }
        rs.erase(src , rs.end());
    }
    return rs;
    }
};
