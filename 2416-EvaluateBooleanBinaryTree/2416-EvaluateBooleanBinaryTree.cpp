// Last updated: 18/07/2026, 19:56:40
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
    bool solve(TreeNode *root)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root->left==NULL and root->right==NULL)
        {
            if(root->val == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool left = solve(root->left);
        bool right = solve(root->right);
        if(root->val == 2)
        {
            return left || right;
        }
        else
        {
            return left and right;
        }

    }  
        
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};