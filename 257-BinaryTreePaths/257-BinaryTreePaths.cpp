// Last updated: 18/07/2026, 20:01:16
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
    void solve(TreeNode *root, vector<string> &ans, string curr)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left or root->right)
        {
            curr += to_string(root->val)+"->";
        }
        if(root->left == NULL and root->right == NULL)
        {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }
        solve(root->left, ans, curr);
        solve(root->right, ans, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr = "";
        vector<string> ans;
        solve(root, ans, curr);
        return ans;
    }
};