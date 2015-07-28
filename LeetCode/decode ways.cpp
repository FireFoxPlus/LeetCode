#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:

int waysToDecoding(string s)
{
    int len = s.length();
    int *rs = new int[len + 1];
    rs[0] = 1;
    for(int i = 1; i <= len; i++)
    {
        if(i - 2 >= 0)
        {
            string cur = s.substr(i - 2 , 2);
            if(cur[1] == '0')
            {
                if(cur[0] == '0')
                {
                    rs[i] = 0;
                    continue;
                }
                if(atoi(cur.c_str()) > 26)
                    rs[i] = 0;
                else
                    rs[i] = rs[i - 2];
            }
            else
            {
                if(cur[0] == '0')
                    rs[i] = rs[i - 1];
                else
                {
                    if(atoi(cur.c_str()) > 26)
                        rs[i] = rs[i - 1];
                    else
                        rs[i] = rs[i - 1] + rs[i - 2];
                }
            }
        }
        else
        {
            if(s[i - 1] == '0')
                rs[i] = 0;
            else
                rs[i] = rs[i - 1];
        }
    }
    return rs[len];
}

int numDecodings(string s)
{
    if(s.length() == 0)
        return 0;
    return waysToDecoding(s);
}
};
