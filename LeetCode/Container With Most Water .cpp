#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int  start = 0 , ends = height.size() - 1;
    int rs = 0;
    while(start < ends)
    {
        rs = max(rs , (ends - start) * min(height[start] , height[ends]));
        if(height[start] < height[ends])
        {
            int tmp = start;
            while(tmp < ends && height[tmp] <= height[start])
                tmp++;
            start = tmp;
        }
        else
        {
            int tmp = ends;
            while(tmp > start && height[tmp] <= height[ends])
                tmp--;
            ends = tmp;
        }
    }
    return rs;
    }
};
