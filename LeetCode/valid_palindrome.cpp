#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
       string::iterator itr;
    for(itr = s.begin(); itr != s.end();)
    {
      if(!isalpha(*itr) && !isdigit(*itr))
        s.erase(itr);
      else
      {
          *itr = toupper(*itr);
          itr++;
      }
    }
    string tmp = s;
    reverse(tmp.begin() , tmp.end());
    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] != s[i])
            return false;
    }
    return true;

    }
};
