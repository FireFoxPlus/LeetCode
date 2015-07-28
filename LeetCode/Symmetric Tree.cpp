
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
    TreeNode *convert(TreeNode *root)
{
    if(root == NULL)
        return NULL;

    TreeNode *cRoot = new TreeNode(1);
    cRoot->val = root->val;
    cRoot->left = convert(root->right);
    cRoot->right = convert(root->left);
    return cRoot;
}

bool isSameTree(TreeNode *croot , TreeNode *root)
{
    if(((croot && root) == 0) && ((croot || root) != 0))
        return false;
    if((croot || root) == 0)
        return true;
    if(croot->val != root->val)
        return false;
    else
        return isSameTree(croot->right , root->right) &&
                isSameTree(croot->left , root->left);
}

bool isSymmetric(TreeNode *root)
{
    if(root == NULL)
        return true;
    TreeNode *cRoot = convert(root);
    return isSameTree(cRoot , root);
}

};
