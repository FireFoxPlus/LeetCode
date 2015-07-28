#include <stdlib.h>


class Solution {
public:
    double pow(double x , int n)
{
    if(n == 1)
        return x;
    double tmpRs = myPow(x , n / 2);
    if(n % 2 == 0)
        return tmpRs * tmpRs;
    else
        return tmpRs * tmpRs * x;
}

double myPow(double x, int n)
{
      if(n == 0)
        return 1;
    double rs = pow(x , abs(n));
    if(n > 0)
        return rs;
    else
        return 1 / rs;
}
};
