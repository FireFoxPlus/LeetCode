#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int height = dungeon.size() , wide = dungeon[0].size();
    vector<vector<int> > flag;
    flag.resize(height);
    for(int i = 0; i < height; i++)
        flag[i].resize(wide);
    //set min health when arrive
    flag[height - 1][wide - 1] = 1 - dungeon[height - 1][wide - 1] > 0 ? 1 - dungeon[height - 1][wide - 1] : 1;
    for(int i = wide - 2; i >= 0; i--)
        flag[height - 1][i] = flag[height - 1][i + 1] - dungeon[height - 1][i] > 0 ? flag[height - 1][i + 1] - dungeon[height - 1][i] : 1;
    for(int i = height - 2; i >= 0; i--)
    {
        for(int j = wide - 1; j >= 0; j--)
        {
            if(j == wide - 1)
            {
                flag[i][j] = flag[i + 1][j] - dungeon[i][j] > 0 ? flag[i + 1][j] - dungeon[i][j] : 1;
            }
            else
            {
                int down = flag[i + 1][j] - dungeon[i][j] > 0 ? flag[i + 1][j] - dungeon[i][j] : 1;
                int right =  flag[i][j + 1] - dungeon[i][j] > 0 ? flag[i][j + 1] - dungeon[i][j] : 1;
                flag[i][j] = min(down , right);
            }
        }
    }
    return flag[0][0];
    }
};
