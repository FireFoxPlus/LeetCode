#include <vector>
using  namespace std;
class Solution {
public:
    int searchInsert(vector<int> &num , int target)
{

    int start = 0 , ends = num.size() - 1;
    int mid = (start + ends) / 2;
    while(start < ends)
    {
        if(num[mid] == target)
            return mid;
        if(num[mid] > target)
            ends = mid - 1;
        else
            start = mid + 1;
        mid = (start + ends) / 2;
    }
    if(num[start] < target)
        return start + 1;
    else
        return start;
}
};
