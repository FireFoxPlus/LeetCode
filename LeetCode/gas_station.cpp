#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int cur = 0 , left = 0 , right = 0 , tank = 0;
    bool start = true;
    int gasLen = gas.size() , costLen = cost.size();
    while(left != right || start)
    {
        start = false;
        if(tank >= 0)
        {
            int righTmp = gas[right] - cost[right];
            tank += righTmp;
            right = (right + gasLen + 1) % gasLen;
        }
        else
        {
            int leftTmp = gas[(left + gasLen - 1) % gasLen] - cost[(left + costLen - 1) % costLen];
            tank += leftTmp;
            left = (left + gasLen - 1) % gasLen;
        }
    }
    if(tank >= 0)
        return left;
    else
        return -1;
    }
};
