#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> last[2];
    last[0] = triangle[triangle.size() - 1];
    int k = 0;
    for(int i = triangle.size() - 2; i >=0; i--)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            int tmp = min(triangle[i][j] + last[k][j] ,
                        triangle[i][j] + last[k][j + 1]);
            last[!k].push_back(tmp);
        }
        last[k].clear();
        k = !k;
    }

    return last[k][0];
    }
};
