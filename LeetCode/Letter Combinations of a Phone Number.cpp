#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   void convert(const char *str , vector<string> &rs , string tmpRs)
{
    vector<vector<char> > dic = {{} , {} , {'a' , 'b' , 'c'} , {'d' , 'e' , 'f'}
                            , {'g' , 'h' , 'i'} , {'j' , 'k' , 'l'}
                            , {'m' , 'n' , 'o'}, {'p' , 'q' , 'r' , 's'}
                            , {'t' , 'u' , 'v'} , {'w' , 'x' , 'y' , 'z'}};

    if(*str == '\0')
    {
        rs.push_back(tmpRs);
        return;
    }
    vector<char> curDic = dic[(*str) - '0'];
    for(int i = 0; i < curDic.size(); i++)
    {
        string tmp = tmpRs + curDic[i];
        convert(str + 1 , rs , tmp);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> rs;
    if(digits.length() == 0)
        return rs;
    string tmpRs;
    const char *str = digits.c_str();
    convert(str , rs , tmpRs);
    return rs;
}
};
