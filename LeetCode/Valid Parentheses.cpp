#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
          int len = s.length();
    if(len == 0)
        return true;
    if(len % 2 != 0)
        return false;
    stack<char> help;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            help.push(s[i]);
        if(s[i] == ')')
        {
            if(help.empty())
                return false;
            if(help.top() == '(')
            {
                help.pop();
                continue;
            }
            else
                return false;
        }
        else if(s[i] == ']')
        {
            if(help.empty())
                return false;
            if(help.top() == '[')
            {
                help.pop();
                continue;
            }
            else
                return false;
        }
        else if(s[i] == '}')
        {
            if(help.empty())
                return false;
            if(help.top() == '{')
            {
                help.pop();
                continue;
            }
            else
                return false;
        }


    }
       if(help.empty())
        return true;
    else
        return false;
    }
};
