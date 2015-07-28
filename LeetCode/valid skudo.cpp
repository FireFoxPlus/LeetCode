#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {

       static bool row[9][9];
    static bool col[9][9];
    static bool box[9][9];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
        {
            row[i][j] = false;
            box[i][j] = false;
            col[i][j] = false;

        }

    if(row[0][0])
        cout<<"true";
    for(int i = 0; i < board.size(); i++)
    {
        vector<char> tmp = board[i];
        for(int j = 0; j < 9; j++)
        {
            if(tmp[j] != '.')
            {
                if(tmp[j] < '0' || tmp[j] > '9')
                    return false;
                if(!row[i][tmp[j] - '1'] && !col[j][tmp[j] - '1']
                   && !box[(i / 3) * 3 + j / 3][tmp[j] - '1'])
                {
                    row[i][tmp[j] - '1'] = true;
                    col[j][tmp[j] - '1'] = true;
                    box[(i / 3) * 3 + j / 3][tmp[j] - '1'] = true;
                }
                else
                    return false;
            }
        }
    }
    return true;
    }
};
