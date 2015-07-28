#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > rs;
    if(n == 0)
        return rs;
    rs.resize(n);
    for(int i = 0; i < n; i++)
        rs[i].resize(n);
    int row = 0 , col = 0;
    int upRow = 0 , downRow = n - 1;
    int leftCol = 0 , rightCol = n - 1;
    for(int i = 1;  i <= n * n;)
    {
        //右
        for(row = upRow , col = leftCol; col <= rightCol; col++)
        {
            rs[row][col] = i;
            i++;
        }
        upRow++;

        //下
        for(row = upRow , col = rightCol; row <= downRow; row++)
        {
            rs[row][col] = i;
            i++;
        }
        rightCol--;
        //左
        for(row = downRow , col = rightCol; col >= leftCol; col--)
        {
            rs[row][col] = i;
            i++;
        }
        downRow--;
        //上
        for(row = downRow , col = leftCol; row >= upRow; row--)
        {
            rs[row][col] = i;
            i++;
        }
        leftCol++;

    }
    return rs;
    }
};
