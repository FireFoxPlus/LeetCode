#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

void twoSum(vector<vector<int> > &rs , int index , vector<int> num)
{
    int start = index + 1 , ends = num.size() - 1;
    while(start < ends)
    {
        if(num[index] + num[start] + num[ends] > 0)
            ends--;
        else if(num[index] + num[start] + num[ends] < 0)
            start++;
        else
        {
            vector<int> tmp;
            tmp.push_back(num[index]);
            tmp.push_back(num[start]);
            tmp.push_back(num[ends]);
            rs.push_back(tmp);
            start++;
            ends--;
            while(start < num.size() && num[start] == num[start - 1])
                start++;
            while(ends >= 0 && num[ends] == num[ends + 1])
                ends--;
        }
    }
}

vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int> > rs;
    if(num.size() == 0)
        return rs;
    sort(num.begin() , num.end());
    for(int i = 0; i < num.size(); i++)
    {
           if(i != 0 && num[i] == num[i - 1])
            continue;
        twoSum(rs , i , num);
    }
    return rs;
}
};
