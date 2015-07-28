
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

TreeNode *buildTree(vector<int> &preorder , int preS , int preE ,
                        vector<int> &inorder , int inS , int inE)
{
    if(preS > preE || inS > inE)
        return NULL;
    int rootVal = preorder[preS];
    TreeNode *root = new TreeNode(rootVal);
    int poi;
    for(poi = inS; poi <= inE; poi++)
    {
        if(inorder[poi] == rootVal)
            break;
    }
    root->left = buildTree(preorder , preS + 1 , preS + poi - inS , inorder , inS , poi - 1);
    root->right = buildTree(preorder , preS + 1  + poi - inS , preE , inorder , poi + 1 , inE);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(inorder.size() == 0 || preorder.size() == 0)
        return NULL;

    return buildTree(preorder , 0 , preorder.size() - 1 ,
                     inorder , 0 , inorder.size() - 1);
}
};
