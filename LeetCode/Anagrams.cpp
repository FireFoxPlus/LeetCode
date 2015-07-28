#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> rs;
    if(strs.size() == 0)
        return rs;
    map<string , int> flag;
    for(int i = 0; i < strs.size(); i++)
    {
        string tmp = strs[i];
        sort(tmp.begin() , tmp.end());
        if(flag.count(tmp) != 0)
        {
            flag[tmp]++;
        }
        else
            flag[tmp] = 1;
    }
    for(int i = 0; i < strs.size(); i++)
    {
        string tmp = strs[i];
        sort(tmp.begin() , tmp.end());
        if(flag[tmp] != 1)
            rs.push_back(strs[i]);
    }
    return rs;
    }
};
