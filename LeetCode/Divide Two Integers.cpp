#include <limits.h>
class Solution {
public:
    void divide(long long &dividend , long long divisor , long long muti, long long &rs)
{
    if(divisor < dividend)
        divide(dividend , divisor + divisor , muti + muti , rs);
    while(dividend >= divisor)
    {
        dividend -= divisor;
        rs += muti;
    }
}

int divide(int dividend , int divisor)
{
    if(divisor == 0)
        return INT_MAX;
    long long div1 = dividend , div2 = divisor;
    int sign = 1;
    if(div1 < 0)
    {
        sign = -1;
        div1 *= -1;
    }
    if(div2 < 0)
    {
        sign *= -1;
        div2 *= -1;
    }
    long long rs = 0;
    divide(div1 , div2 , 1 , rs);
    if(rs * sign > INT_MAX)
        return INT_MAX;
    else
        return rs * sign;
}
};
