
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool balanceJudge(TreeNode *root , int *depth)
{
    if(root == NULL)
    {
        *depth = 0;
        return true;
    }
    int left , right;
    bool leftB , rightB;
    leftB = balanceJudge(root->left , &left);
    rightB = balanceJudge(root->right , &right);
    *depth = left > right ? left + 1 : right + 1;
    if(left - right >= -1 && left - right <= 1 && leftB && rightB)
        return true;
    else return false;
}

bool isBalanced(TreeNode *root)
{
    if(root == NULL)
        return true;
    int depth;
    return balanceJudge(root , &depth);
}
};
