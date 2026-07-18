// Last updated: 18/07/2026, 20:03:23
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
  
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return false;
        }
        sum = sum-root->val;                                             
        if(sum == 0 and !root->left and !root->right)
        {
            return true;  
        }
        return hasPathSum(root->left,sum) or hasPathSum(root->right,sum);
    }
};