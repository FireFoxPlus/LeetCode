#include <vector>
using namespace std;
class Solution {
public:
 vector<int> plusOne(vector<int> &digits , int len)
{
    vector<int> carry;
    if(len == 0)
    {
        digits.insert(digits.begin() , 1);
        return digits;
    }
    int tmp = digits[len - 1] + 1;
    digits[len - 1] = tmp % 10;
    if(tmp >= 10)
        return plusOne(digits , len - 1);
    else
        return digits;

}

vector<int> plusOne(vector<int>& digits)
{
    return plusOne(digits , digits.size());
}

};
