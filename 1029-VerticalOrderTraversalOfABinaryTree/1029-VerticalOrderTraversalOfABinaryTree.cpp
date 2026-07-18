// Last updated: 18/07/2026, 19:59:06
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int height = q.front().second.first;
            int level =q.front().second.second;
            nodes.emplace_back(height, level, temp->val);
            if(temp->left){
                q.push({temp->left, {height-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right, {height+1,level+1}});
            }
            q.pop();
        }
        sort(nodes.begin(), nodes.end());
        int prevCol=INT_MIN;
        for(auto [col, row, val] : nodes){
            if(col!=prevCol){
                ans.push_back({});
                prevCol=col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};