// Last updated: 18/07/2026, 19:58:33
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
    int ans = 0;
    void solve(TreeNode *root, int curMax){
        if(!root){
            return;
        }
        if(root->val >= curMax){
            ans++;
            curMax=root->val;
        }
        solve(root->left, curMax);
        solve(root->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};