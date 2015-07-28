#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
           vector<int> rs(rowIndex + 1 , 0);
    rs[0] = 1;
    for(int i = 1; i <= rowIndex; i++)
        for(int j = i; j >= 1; j--)
        {
            rs[j] = rs[j] + rs[j - 1];
        }
    return rs;

    }
};
