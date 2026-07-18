// Last updated: 18/07/2026, 20:00:47
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
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = 0, right = 0;
        if(dp[root]!=0)
        {
            return dp[root];
        }
        if(root->left)
        {
            left = solve(root->left->left)+solve(root->left->right);
        }
        if(root->right)
        {
            right = solve(root->right->left)+solve(root->right->right);
        }
        return dp[root] = max(root->val+left+right, solve(root->left)+solve(root->right));
    }
    int rob(TreeNode* root) {
      return solve(root);
    }
};