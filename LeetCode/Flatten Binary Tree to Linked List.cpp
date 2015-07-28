
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
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
   void toList(TreeNode *root , TreeNode **head)
{
    if(root == NULL)
        return;

    toList(root->right , head);
    toList(root->left , head);
    root->right = *head;
    *head = root;
    root->left = NULL;
}

void flatten(TreeNode *root)
{
    if(root == NULL)
        return;
    TreeNode *listHead = NULL;
    toList(root , &listHead);
}
};
