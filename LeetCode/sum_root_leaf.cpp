
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

void getSum(TreeNode *root , int *sum , int nowSum)
{
    if(root == NULL)
    {
        return;
    }

    nowSum = nowSum * 10 + root->val;
    if(root->left == NULL && root->right == NULL)
    {
        *sum += nowSum;
        return;
    }

    getSum(root->left , sum , nowSum);
    getSum(root->right , sum , nowSum);

}

int sumNumbers(TreeNode *root)
{
    if(root == NULL)
    return 0;
    if(root->left == NULL && root->right == NULL)
        return root->val;
    int sum = 0;
    int nowSum = root->val;
    getSum(root->left , &sum , nowSum);
    getSum(root->right , &sum , nowSum);
    return sum;
}
};
