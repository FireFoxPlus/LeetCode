
/**
 * Definition for a binary tree node.
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

void postorder(TreeNode *root , vector<int> &rs)
{
    if(root == NULL)
        return;
    postorder(root->left , rs);
    postorder(root->right , rs);
    rs.push_back(root->val);

}

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> rs;
    if(root == NULL)
        return rs;
    postorder(root , rs);
    return rs;
}
};
