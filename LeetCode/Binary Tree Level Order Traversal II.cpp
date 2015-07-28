
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

void DFS(TreeNode *root , vector<vector<int> > &rs , int dep)
{
    if(root == NULL)
        return;
    if(rs.empty() || rs.size() - 1 < dep)
        rs.push_back(vector<int> ());

    rs[dep].push_back(root->val);
    DFS(root->left , rs , dep + 1);
    DFS(root->right , rs , dep + 1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    vector<vector<int> > rs;
    if(root == NULL)
        return rs;
    DFS(root,  rs , 0);
    reverse(rs.begin() , rs.end());
    return rs;
}

};
