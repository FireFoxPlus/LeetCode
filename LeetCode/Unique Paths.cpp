#include <stdlib.h>
class Solution {
public:
    int uniquePaths(int m, int n) {
         int (*rs)[n] = (int (*)[n])malloc(sizeof(int) * n * m);
    for(int i = 0; i < n; i++)
        rs[0][i] = 1;
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
                rs[i][j] = rs[i - 1][j];
            else
                rs[i][j] = rs[i - 1][j] + rs[i][j - 1];
        }
    }
    return rs[m - 1][n - 1];
    }
};
