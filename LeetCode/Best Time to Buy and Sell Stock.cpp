#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         vector<int> value;
    for(int i  = 1; i < prices.size(); i++)
        value.push_back(prices[i] - prices[i - 1]);

    int sum = 0 , maxSum = 0;
    for(int i = 0; i < value.size(); i++)
    {
        sum += value[i];
        if(sum > maxSum)
            maxSum = sum;
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
    }
};
