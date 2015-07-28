
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

TreeNode *buildTree(vector<int> &inorder , int inS , int inE ,
                        vector<int> &postorder , int poS , int poE)
{
    if(inS > inE || poS > poE)
        return NULL;
    int rootVal = postorder[poE];
    TreeNode *root = new TreeNode(rootVal);
    int poi;
    for(poi = inS; poi <= inE; poi++)
    {
        if(inorder[poi] == rootVal)
            break;
    }
    root->left = buildTree(inorder , inS , poi - 1 , postorder , poS , poE - inE + poi - 1);
    root->right = buildTree(inorder , poi + 1 , inE , postorder , poS + poi - inS , poE - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if(inorder.size() == 0 || postorder.size() == 0)
        return NULL;

    return buildTree(inorder , 0 , inorder.size() - 1 ,
                     postorder , 0 , postorder.size() - 1);
}
};
