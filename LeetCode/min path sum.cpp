#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
          vector<vector<int> > pathSum;
    int height = grid.size() , wide = grid[0].size();
    pathSum.resize(height);
    int counts = 0;
    pathSum[height - 1].resize(wide , 0);
    for(int i = wide - 1; i >= 0; i--)
    {
        counts += grid[height - 1][i];
        pathSum[height - 1][i] = counts;
    }
    for(int i = height - 2; i >= 0; i--)
    {
        pathSum[i].resize(wide , 0);
        for(int j = wide - 1; j >= 0; j--)
        {
            if(j == wide - 1)
                pathSum[i][j] = grid[i][j] + pathSum[i + 1][j];
            else
                pathSum[i][j] = grid[i][j] + min(pathSum[i + 1][j] , pathSum[i][j + 1]);
        }
    }
    return pathSum[0][0];
    }
};
