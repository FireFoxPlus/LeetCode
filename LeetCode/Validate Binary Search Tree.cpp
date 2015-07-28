
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
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void in_tra(struct TreeNode * root, int * stack, int * top)
{
    if(!root) return;
    in_tra(root->left, stack, top);
    stack[(*top)++] = root->val;
    in_tra(root->right, stack, top);
}


bool isValidBST(struct TreeNode *root)
{
    int stack[10000];
    int top = 0;
    int i;

    in_tra(root, stack, &top);

    for(i = 1; i < top; ++i)
    {
        if(stack[i] <= stack[i - 1]) return false;
    }
    return true;
}
};
