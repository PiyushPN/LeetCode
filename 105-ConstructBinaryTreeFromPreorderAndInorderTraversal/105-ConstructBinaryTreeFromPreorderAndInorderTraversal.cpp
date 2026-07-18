// Last updated: 18/07/2026, 20:03:31
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
    TreeNode* solve(vector<int>& pre, vector<int>& in, int start, int end, int &index){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[index++]);
        int inIndex=0;
        for(int i=start; i<=end; i++){
            if(in[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->left = solve(pre, in, start, inIndex-1, index);
        root->right = solve(pre, in, inIndex+1, end, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        int index=0;
        return solve(pre, in, 0, n-1, index);
    }
};