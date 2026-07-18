// Last updated: 18/07/2026, 19:58:34
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    void solve(TreeNode* root, int target){
        if(root == NULL){
            return;
        }
        if(root->val == target)
        {
            ans = root;
            return;
        }
        solve(root->left, target);
        solve(root->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int value = target->val;
        solve(cloned, value);
        return ans;
    }
};