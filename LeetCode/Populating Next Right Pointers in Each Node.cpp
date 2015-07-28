
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void BFS(queue<TreeLinkNode *> &que)
{
    queue<TreeLinkNode *> next;
    if(que.empty())
        return;
    TreeLinkNode *cur , *pre = NULL;
    while(!que.empty())
    {
        cur = que.front();
        que.pop();
        if(pre != NULL)
            pre->next = cur;
        pre = cur;
        if(cur->left != NULL)
            next.push(cur->left);
        if(cur->right != NULL)
            next.push(cur->right);
    }
    BFS(next);
}
void connect(TreeLinkNode *root)
{
    if(root == NULL)
        return;
    queue<TreeLinkNode *> que;
    que.push(root);
    BFS(que);
}
};
