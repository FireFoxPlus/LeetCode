#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
    if(len == 0)
        return;
    string::iterator start = s.begin();
    while(start != s.end() && *start == ' ')
    {
        start = s.erase(start);
        len--;
    }
    for(start = s.begin(); start != s.end();)
    {
        if(*start == ' ' && *(start + 1) == ' ')
        {
            start = s.erase(start);
            len--;
        }
        else if(*start == ' ' && start + 1 == s.end())
        {
             start = s.erase(start);
             len--;
        }
        else
            start++;
    }
    reverse(s.begin() , s.end());
    for(int i = 0; i < len; i++)
    {
        int tmp = i;
        while(s[tmp] != ' ' && tmp < len)
            tmp++;
        reverse(&s[i] , &s[tmp]);
        i = tmp;
    }
    }
};
