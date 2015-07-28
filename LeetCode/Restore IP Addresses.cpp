#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:

void restore(string s , vector<string> &rs , string tmpRs , int poi)
{
    if(poi == 4 && s.length() == 0)
    {
        tmpRs.erase(tmpRs.length() - 1 , 1);
        rs.push_back(tmpRs);
        return;
    }
    else if(poi == 4)
        return;
    string copys = tmpRs;
    for(int i = 1; i < 4 && i < s.length() + 1; i++)
    {
        int ien = s.length();
        string fir = s.substr(0 , i);
         if((fir[0] == '0') && (fir.length() > 1))
            {
                return;
            }
        const char *fir_cstr = fir.c_str();
        int tmpIntRs = atoi(fir_cstr);
        if(tmpIntRs > 255)
            continue;
        char split = '.';
        tmpRs.append(fir_cstr);
        tmpRs.append(&split , 1);
        string suf = s.substr(i);
        restore(suf , rs , tmpRs , poi + 1);
        tmpRs = copys;
    }
}

vector<string> restoreIpAddresses(string s)
{
    string a;
    vector<string> rs;
    string tmpRs;
    restore(s , rs , tmpRs , 0);
    return rs;
}

};
