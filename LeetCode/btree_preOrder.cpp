
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
    vector<int> preorderTraversal(TreeNode *root) {
       stack<TreeNode *> help;
    vector<int> rs;
    if(root == NULL)
        return rs;
    help.push(root);
    while(!help.empty())
    {
        TreeNode *tmp = help.top();
        help.pop();
        rs.push_back(tmp->val);
         if(tmp->right != NULL)
            help.push(tmp->right);
        if(tmp->left != NULL)
            help.push(tmp->left);
    }
    return rs;
    }
};
