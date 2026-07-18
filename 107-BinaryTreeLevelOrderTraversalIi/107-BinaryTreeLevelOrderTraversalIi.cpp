// Last updated: 18/07/2026, 20:03:28
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
    int depth(TreeNode *root){
        if(!root){
            return 0;
        }
        return max(depth(root->left), depth(root->right))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d=depth(root);
        vector<vector<int>> ans(d, vector<int> {});
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, d-1});
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode *node = q.front().first;
                int level = q.front().second;
                q.pop();
                ans[level].push_back(node->val);
                if(node->left){
                    q.push({node->left, level-1});
                }
                if(node->right){
                    q.push({node->right, level-1});
                }
            }
        }
        return ans;
    }
};