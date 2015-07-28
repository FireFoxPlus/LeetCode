#include <vector>
using namespace std;

class Solution {
public:


void DFS(vector<vector<char> > &grid , int i , int j)
{
    grid[i][j] = '2';//访问过
    if(i - 1 >= 0 && grid[i - 1][j] == '1')
        DFS(grid , i - 1 , j);
    if(j - 1 >= 0 && grid[i][j - 1] == '1')
        DFS(grid , i , j - 1);
    if(i + 1 < grid.size() && grid[i + 1][j] == '1')
        DFS(grid , i + 1 , j);
    if(j + 1 < grid[i].size() && grid[i][j + 1] == '1')
        DFS(grid , i , j + 1);
}


int numIslands(vector<vector<char> > &grid)
{
    int counts = 0;
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                counts++;
                DFS(grid , i , j);
            }
        }
    return counts;
}
};
