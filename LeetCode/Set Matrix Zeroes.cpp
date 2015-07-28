#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        unordered_set<int> row , col;
    for(int i = 0; i < matrix.size(); i++)
    {
        vector<int> tmp = matrix[i];
        for(int j = 0; j < tmp.size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++)
    {
        vector<int> tmp = matrix[i];
        for(int j = 0; j < tmp.size(); j++)
        {
            if(row.count(i) != 0 || col.count(j) != 0)
                matrix[i][j] = 0;
        }
    }
    }
};
