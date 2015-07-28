
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
 #include <algorithm>

 using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    void DFS(vector<vector<int> > &rs , TreeNode *root , int dep)
{
    if(root == NULL)
        return;
    if(rs.size() < dep)
        rs.push_back(vector<int>());
    rs[dep - 1].push_back(root->val);
    DFS(rs , root->left , dep + 1);
    DFS(rs , root->right , dep + 1);
}


vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int> > rs;
    if(root == NULL)
        return rs;
    DFS(rs , root , 1);
    for(int i = 0; i < rs.size(); i++)
    {
        if(i % 2 != 0)
            reverse(rs[i].begin() , rs[i].end());

    }
    return rs;
}
};
