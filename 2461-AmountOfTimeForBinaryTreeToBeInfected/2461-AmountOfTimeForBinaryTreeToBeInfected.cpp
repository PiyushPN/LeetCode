// Last updated: 18/07/2026, 19:56:21
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
    TreeNode *st = NULL;
    void solve(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &mp, int start, unordered_map<TreeNode*, int> &vis)
    {
        if(root==NULL)
        {
            return;
        }
        vis[root] = 0;
        if(root->val == start)
        {
            st = root;
        }
        if(root->left)
        {
            mp[root->left] = root;
        }
        if(root->right)
        {
            mp[root->right] = root;
        }
        solve(root->left, mp, start, vis);
        solve(root->right, mp, start, vis);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*, int> vis;
        solve(root, par, start, vis);
        int ans = 0;
        queue<TreeNode*> q;
        q.push(st);
        vis[st] = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                //vis[temp] = 1;
                if(temp->left and vis[temp->left] == 0)
                {
                    q.push(temp->left);
                    vis[temp->left] = 1;
                }
                if(temp->right and vis[temp->right] == 0)
                {
                    q.push(temp->right);
                    vis[temp->right] = 1;
                }
                if(par.find(temp) != par.end() and vis[par[temp]] == 0)
                {
                    q.push(par[temp]);
                    vis[par[temp]] = 1;
                }
            }
            ans++;
        }
        return ans-1;
    }
};