#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<int> value;
    for(int i  = 1; i < prices.size(); i++)
        value.push_back(prices[i] - prices[i - 1]);
    int maxGain = 0;
    for(int i = 0; i < value.size(); i++)
    {
        if(value[i] > 0)
            maxGain += value[i];
    }
    return maxGain;
    }
};
