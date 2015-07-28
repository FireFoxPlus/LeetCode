#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
      int rs = 0;
    for(int i = 0; i < s.size(); i++)
    {
        rs = rs * 26 + s[i] - 'A' + 1;
    }
    return rs;
    }
};
