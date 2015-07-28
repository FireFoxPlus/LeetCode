#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length() , len2 = needle.length();
    if(len2 == 0)
        return 0;
    if(needle.length() > len1)
        return -1;
    for(int i = 0; i < len1; i++)
    {
        if(len1 - i + 1 < len2)
            return -1;
        if(haystack[i] == needle[0])
        {
            bool found = true;
            int j , k;
            for(j = i , k = 0; j < len1 && k < len2; j++ , k++)
            {
                if(haystack[j] != needle[k])
                {
                    found = false;
                    break;
                }
            }
            if(k < len2)
                found = false;
            if(found)
                return i;
        }
    }
    return -1;

    }
};
