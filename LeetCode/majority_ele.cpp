#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &num) {
    int counts = 0;
    int rs;
    for(int i = 0; i < num.size(); i++)
    {
        if(i == 0)
        {
            rs = num[0];
            counts++;
            continue;
        }
        if(num[i] != rs)
        {
            counts--;
            if(counts == 0)
            {
                rs = num[i];
                counts = 1;
            }

        }
        else
        {
            counts++;
        }
    }
    return rs;

    }
};
