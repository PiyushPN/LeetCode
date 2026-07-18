// Last updated: 18/07/2026, 19:59:48
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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        ans=max(ans, left+right);
        return 1+max(right, left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};