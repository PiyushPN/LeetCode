// Last updated: 18/07/2026, 20:03:22
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
    void solve(TreeNode* root, int target, vector<vector<int>> &ans, vector<int> temp, int sum)
    {
        if(root == NULL)
        {
            return;
        }
        temp.push_back(root->val);
        sum += root->val;
        if(sum == target and root->left == NULL and root->right == NULL)
        {
            ans.push_back(temp);
            sum = 0;
            temp.clear();
        }
        solve(root->left, target, ans, temp, sum);
        solve(root->right, target, ans, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};