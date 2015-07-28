#include <iostream>
#include <vector>
using namespace std;
/*Definition for binary tree*/
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
    if(rs.empty() || rs.size() < dep + 1)
        rs.push_back(vector<int>());

    rs[dep].push_back(root->val);
    DFS(root->left , rs , dep + 1);
    DFS(root->right , rs , dep + 1);
}

vector<int> rightSideView(TreeNode *root)
{

    vector<vector<int> > tmpRs;
    vector<int> rs;
    if(root == NULL)
        return rs;
    DFS(root , tmpRs , 0);
    for(int i = 0; i < tmpRs.size(); i++)
        rs.push_back(tmpRs[i].back());
    return  rs;
}

};
