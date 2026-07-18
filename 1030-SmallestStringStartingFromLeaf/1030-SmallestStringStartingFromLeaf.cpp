// Last updated: 18/07/2026, 19:59:04
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
    string ans = "~";
    void solve(TreeNode* root, string temp){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            ans = min(ans, char('a'+root->val)+temp);
        }
        solve(root->left, char('a'+root->val)+temp);
        solve(root->right, char('a'+root->val)+temp);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};