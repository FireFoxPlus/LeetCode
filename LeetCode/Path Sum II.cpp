
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
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
    void DFS(vector<vector<int> > &rs , TreeNode *root , int sum ,
         vector<int> nowPath)
{
    if(root->left == NULL && root->right == NULL)
    {
        if(sum == root->val)
        {
            nowPath.push_back(root->val);
            rs.push_back(nowPath);
        }
        return;
    }
    sum -= root->val;
    nowPath.push_back(root->val);
    if(root->left != NULL)
        DFS(rs , root->left , sum , nowPath);
    if(root->right != NULL)
        DFS(rs , root->right , sum , nowPath);
}
vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    vector<vector<int> > rs;
    if(root == NULL)
        return rs;
    vector<int> nowPath;
    DFS(rs , root , sum , nowPath);
}
};
