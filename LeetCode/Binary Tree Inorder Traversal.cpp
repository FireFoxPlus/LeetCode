
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
#include <stack>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> rs;
    if(root == NULL)
        return rs;
    stack<TreeNode *> help;
    TreeNode * tmp = root;
    while(tmp != NULL || !help.empty())
    {
        while(tmp != NULL)
        {
            help.push(tmp);
            tmp = tmp->left;
        }

        TreeNode *cur = help.top();
        help.pop();
        rs.push_back(cur->val);
        tmp = cur->right;
    }
    return rs;
    }
};
