
class Solution {
public:

bool isValid(long long i , long long x)
{
    if(((i * i) == x) || ((i * i) < x && (i + 1) * (i + 1) > x))
        return true;
    return false;
}

int mySqrt(int x)
{
    long long start = 0 , ends = x;
    long long mid = (start + ends) / 2;
    while(start < ends)
    {
        if(isValid(mid , x))
            return mid;
        if(mid * mid > x)
            ends = mid - 1;
        else
            start = mid + 1;
        mid = (start + ends) / 2;
    }
    return start;
}
};
