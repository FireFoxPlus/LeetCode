
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
void DFS(TreeNode *root , vector<vector<int> > &rs , int deepth)
{
    if(root == NULL)
        return;

    if(rs.size() <= deepth)
    {
        vector<int> tmp;
        rs.push_back(tmp);
    }

    rs[deepth].push_back(root->val);

    DFS(root->left , rs ,deepth + 1);
    DFS(root->right  , rs , deepth + 1);
}
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rs;
    DFS(root , rs , 0);
    return rs;

    }
};
