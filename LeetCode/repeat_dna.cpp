#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       map<int , int> help;
    vector<string> rs;
    int len = s.length();
    hash<string> strToint;

    if(len < 10)
        return rs;
    for(int i = 0; i < len - 9; i++)
    {
        string tmp(&s[i] , &s[i + 10]);
        map<int , int>::iterator itr;
        itr = help.find(strToint(tmp));
        if(itr == help.end())
            help.insert(map<int , int>::value_type(strToint(tmp) , 1));
        else
        {
            if(itr->second == 1)
                rs.push_back(tmp);
            itr->second = itr->second + 1;
        }

    }
    return rs;
    }
};
