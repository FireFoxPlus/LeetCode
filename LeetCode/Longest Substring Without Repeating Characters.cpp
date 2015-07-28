#include <string>
#include <memory.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256];
    memset(flag , -1 , sizeof(int) * 256);
    int maxs = 0 , start = -1;
    for(int i = 0; i < s.length(); i++)
    {
        if(flag[s[i]] > start)
        {
            start = flag[s[i]];
            flag[s[i]] = i;
            continue;
        }
        else
        {
            if(i - start > maxs)
                maxs = i - start;
            flag[s[i]] = i;
        }
    }
    return maxs;
    }
};
