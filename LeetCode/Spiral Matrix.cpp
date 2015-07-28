#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
         vector<int> rs;
 if(matrix.size() == 0)
        return rs;
    int upRow = 0 , downRow = matrix.size() - 1;
    int leftCol = 0 , rightCol = matrix[0].size() - 1;
    int row = 0 , col = 0;
    while(upRow <= downRow && leftCol <= rightCol)
    {
        //右
        for(col = leftCol , row = upRow; col <= rightCol; col++)
        {
            rs.push_back(matrix[row][col]);
        }
        upRow++;
        if(upRow > downRow)
            break;
        //下
        for(row = upRow , col = rightCol; row <= downRow; row++)
        {
            rs.push_back(matrix[row][col]);
        }
        rightCol--;
        if(rightCol < leftCol)
            break;
        //左
        for(col = rightCol , row = downRow; col >= leftCol; col--)
        {
            rs.push_back(matrix[row][col]);
        }
        downRow--;
        if(upRow > downRow)
            break;
        //上
        for(row = downRow , col = leftCol; row >= upRow; row--)
        {
            rs.push_back(matrix[row][col]);
        }
        leftCol++;
        if(leftCol > rightCol)
            break;
    }
    return rs;
    }
};
