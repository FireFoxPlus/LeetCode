#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.length() == 0)
        return true;
    if(wordDict.count(s) != 0)
        return true;
    int len = s.length();
    bool *flage = new bool[len + 1];
    for(int i = 0; i < len + 1; i++)
        flage[i] = false;
    flage[0] = true;
    for(int i = 1; i < len + 1; i++)
    {
        for(int j = 0; j < i; j++)
        {
            string tmp = s.substr(j , i - j);
            if(flage[j] && wordDict.count(tmp) != 0)
            {
                flage[i] = true;
                break;
            }
        }
    }
    return flage[len];
    }
};
