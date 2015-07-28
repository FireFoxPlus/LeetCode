#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >rs;
    for(int i = 1; i <= numRows; i++)
    {
        vector<int> line(i , 0);
        line[0] = 1;
        for(int j = 0; j < i; j++)
        {
            if(j == 0 || j == i - 1)
                line[j] = 1;
            else
                line[j] = rs[i - 2][j - 1] + rs[i - 2][j];
        }
        rs.push_back(line);
    }
    return rs;

    }
};
