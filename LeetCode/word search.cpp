#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   bool exist(vector<vector<char> > &board, string word) {
    for (int i = 0; i<board.size(); i++)
        for (int j = 0; j<board[0].size(); j++)
            if (exist(board, word.c_str(), i, j))
                return true;
    return false;
}

bool exist(vector<vector<char> > &board, const char* word, int row, int col) {
    if (*word != board[row][col] || board[row][col] == NULL)
        return false;

    if (*(word + 1) == NULL)
        return true;

    char t = board[row][col];
    board[row][col] = NULL;

    if (row > 0 && exist(board, word + 1, row - 1, col)
        || col > 0 && exist(board, word + 1, row, col - 1)
        || row < board.size() - 1 && exist(board, word + 1, row + 1, col)
        || col < board[0].size() - 1 && exist(board, word + 1, row, col + 1))
        return true;

    board[row][col] = t;

    return false;
  }
};
