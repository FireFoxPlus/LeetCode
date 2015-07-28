#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    string add(string num1 , string num2)
{
    string rs;
    while(num1.length() < num2.length())
    {
        num1.insert(0 , "0" , 1);
    }

    while(num1.length() > num2.length())
    {
        num2.insert(0 , "0" , 1);
    }

    string tmpRs , carry;
    for(int i = 0; i < num1.length(); i++)
    {
        tmpRs += (num1[i] - '0' + num2[i] - '0') % 10 + '0';
        if((num1[i] - '0' + num2[i] - '0') / 10 != 0 || i != 0)
            carry += (num1[i] - '0' + num2[i] - '0') / 10  + '0';
    }
    carry += "0";
    const char *str =  carry.c_str();
    if(atoi(str) != 0)
        return add(tmpRs , carry);
    else
        return tmpRs;
}

void eraseZero(string &str)
{
    for(string::iterator itr = str.begin(); itr != str.end(); )
    {
        if(*itr ==  '0')
            itr = str.erase(itr);
        else
            return;
    }
}



string multiply(string num1, string num2)
{
    string rs = "0";
    int len1 = num1.length() , len2 = num2.length();
    //num1
    //*
    //num2,use every digit in num2 to multiply num1
    //乘数
    for(int i = 0; i < len2; i++)
    {
        string carry , rsNoCarry , midRs;
        //被乘数
        for(int j = 0; j < len1; j++)
        {
            char tmpDidgit = ((num2[len2 - 1 - i] - '0') * (num1[len1 - 1 - j] - '0')) % 10 + '0';
            rsNoCarry.insert(0 , &tmpDidgit , 1);
            tmpDidgit = ((num2[len2 - 1 - i] - '0') * (num1[len1 - 1 - j] - '0')) / 10 + '0';
            carry.insert(0 , &tmpDidgit , 1);
        }
        eraseZero(carry);
        carry += "0";
        midRs = add(carry , rsNoCarry);
        for(int k = 0; k < i; k++)
            midRs += "0";
        rs = add(midRs , rs);
    }
      eraseZero(rs);
    if(rs.length() == 0)
        return "0";
    return rs;
}
};
