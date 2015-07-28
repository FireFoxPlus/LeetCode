#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;
class Solution {
public:

static int getLen(int val)
{
    int len = 0;
    if(val == 0)
        return 1;
    while(val != 0)
    {
        len++;
        val /= 10;
    }
    return len;
}

static bool compare(int val1 , int val2)
{
    int len1 = getLen(val1) , len2 = getLen(val2);
    return pow(10 , len2) * val1 + val2 > pow(10 , len1) * val2 + val1;
}
string largestNumber(vector<int>& num)
{
     string rs;
    if(num.empty())
        return rs;
    sort(num.begin() , num.end() , compare);
    bool allZero = true;
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] != 0)
        {
            allZero = false;
            break;
        }
    }
    if(allZero)
        return rs.append("0" , 1);

    for(int i = 0; i < num.size(); i++)
    {
        int tmp = num[i];
        string cur;
        if(tmp == 0)
        {
            rs = rs + "0";
            continue;
        }
        while(tmp != 0)
        {
            char tmpChar = tmp % 10 + '0';
            cur.insert(0 , &tmpChar , 1);
            tmp /= 10;
        }
        rs += cur;
    }
    return rs;
}
};
