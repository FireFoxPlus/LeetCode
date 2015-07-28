#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    bool rs;
    map<char , int> fir , sec;
    int index = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(fir.count(s[i]) == 0)
        {
            fir[s[i]] = index;
            index++;
        }
        s[i] = fir[s[i]];
    }
    index = 0;
    for(int i = 0; i < t.length(); i++)
    {
        if(sec.count(t[i]) == 0)
        {
            sec[t[i]] = index;
            index++;
        }
        t[i] = sec[t[i]];
    }
    return s == t;
    }
};
