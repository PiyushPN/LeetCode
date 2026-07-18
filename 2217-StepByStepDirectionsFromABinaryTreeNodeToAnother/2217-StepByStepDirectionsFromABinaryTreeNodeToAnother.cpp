// Last updated: 18/07/2026, 19:57:42
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
    TreeNode *lca(TreeNode *root, int s, int d)
    {
        if(root == NULL or root->val == s or root->val == d)
        {
            return root;
        }
        TreeNode *left = lca(root->left, s, d);
        TreeNode *right = lca(root->right, s, d);
        if(left != NULL and right != NULL)
        {
            return root;
        }
        if(left == NULL)
        {
            return right;
        }
        else
        {
            return left;
        }
    }
    void solve(TreeNode* root, string &ans, int data, string &s) {
        if(root == NULL)
        {
            return;
        }
        if(root->val == data)
        {
            ans = s;
            return;
        }
        s.push_back('L');
        solve(root->left, ans, data, s);
        s.pop_back();
        s.push_back('R');
        solve(root->right, ans, data, s);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode *temp = lca(root, startValue, destValue);
        string lca1= "", lca2 = "";
        string str = "";
        solve(temp, lca1, startValue, str);
        str = "";
        solve(temp, lca2, destValue, str);
        // for(int i = 0; i < lca1.length(); i++)
        // {
        //     lca1[i] = 'U';
        // }
        lca1 = string(lca1.length(), 'U');
        return lca1+lca2;
        
    }
};