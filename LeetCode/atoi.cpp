#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1 , start = 0;
    while(str[start] == ' ')
        start++;
    if(!isdigit(str[start]))
    {
        if(str[start] == '-')
        {
            sign = -sign;
            start++;
        }
        else if(str[start] == '+')
            start++;
    }
    long long  rs = 0;
    while(start < str.length() && isdigit(str[start]))
    {
        rs = rs * 10 + str[start] - '0';
        start++;
        if(rs *sign > INT_MAX)
            return INT_MAX;
        else if(rs * sign< INT_MIN)
            return INT_MIN;
    }
    return rs * sign;
    }
};
