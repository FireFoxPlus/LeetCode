#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

    int maxs = 0;
    string rs;
    //一个为中心
    for(int i = 0; i < s.length(); i++)
    {

        if(i == 0)
        {
            maxs = 1;
            rs = s.substr(0 , 1);
            continue;
        }
        for(int j = 1; j < s.length(); j++)
        {
            if(i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j])
            {
                if(2 * j + 1 > maxs)
                {
                    maxs = 2 * j + 1;
                    rs = s.substr(i - j , maxs);
                }
            }
            else
                break;
        }
    }
    //两个为中心
    for(int i = 1; i < s.length(); i++)
    {
        for(int j = 0; j < s.length(); j++)
        {
            if(i - 1 - j >= 0 && i + j < s.length() && s[i - 1 - j] == s[i + j])
            {
                if(2 * j + 2 > maxs)
                {
                    maxs = 2 * j + 2;
                    rs = s.substr(i - 1 - j , maxs);
                }
            }
            else
                break;
        }

    }
    return rs;
    }
};
