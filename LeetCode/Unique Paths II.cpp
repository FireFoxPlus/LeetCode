#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int height = obstacleGrid.size() , wide = obstacleGrid[0].size();
    int (*rs)[wide] = (int (*) [wide])malloc(sizeof(int) * wide * height);
    for(int i = 0; i < wide; i++)
    {
        if(i == 0)
        {
            if(obstacleGrid[0][0] == 1)
                rs[0][0] = 0;
            else
                rs[0][0] = 1;
        }
        else
        {
            if(obstacleGrid[0][i] == 1)
                rs[0][i] = 0;
            else
                rs[0][i] = rs[0][i - 1];
        }
    }
    for(int i = 1; i < height; i++)
    {
        for(int j = 0; j < wide; j++)
        {
            if(j == 0)
            {
                if(obstacleGrid[i][j] == 1)
                    rs[i][j] = 0;
                else
                    rs[i][j] = rs[i - 1][j];
            }
            else
            {
                if(obstacleGrid[i][j] == 1)
                    rs[i][j] = 0;
                else
                    rs[i][j] = rs[i - 1][j] + rs[i][j - 1];
            }
        }
    }
    return rs[height - 1][wide - 1];
    }
};
