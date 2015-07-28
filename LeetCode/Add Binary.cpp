#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
         string rs;
    int lenA = a.length() , lenB = b.length();
    if(lenA < lenB)
    {
        for(int i = 0; i < lenB - lenA; i++)
            a.insert(0 , "0" , 1);
    }
    else if(lenB <lenA)
    {
        for(int i = 0; i < lenA - lenB; i++)
            b.insert(0 , "0" , 1);
    }
    string carry , sum;
    for(int i = 0; i < a.length(); i++)
    {
        char tmpSum = ((a[i] - '0') ^ (b[i] - '0')) + '0';
       char tmpCarry = ((a[i] - '0') & (b[i] - '0')) + '0';
        sum.append(&tmpSum , 1);
        carry.append(&tmpCarry , 1);
    }
    carry.append("0" , 1);
    //检测carry是否为0
    int i = 0;
    for(; i < carry.size(); i++)
        if(carry[i] != '0')
            break;
    if(i == carry.size())
        rs = sum;
    else
        rs = addBinary(sum , carry);

    i = 0;
    for(; i < rs.size(); i++)
        if(rs[i] != '0')
            break;
    if(i != rs.size())
    {
        for(string::iterator itr = rs.begin(); itr != rs.end() && *itr == '0';)
        {
            if(*itr == '0')
                rs.erase(itr);
            else
                itr++;
        }
    }
    return rs;
    }
};
