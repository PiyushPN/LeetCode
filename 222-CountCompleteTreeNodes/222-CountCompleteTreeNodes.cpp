// Last updated: 18/07/2026, 20:01:36
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        return l+r+1;
    }
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        return solve(root);
    }
};