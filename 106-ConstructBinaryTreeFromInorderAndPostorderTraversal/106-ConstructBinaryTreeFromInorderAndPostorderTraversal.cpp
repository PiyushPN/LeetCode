// Last updated: 18/07/2026, 20:03:30
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
    TreeNode* solve(vector<int>& in, vector<int> &post, int start, int end, int &index){
        if(start>end){
            return NULL;
        }
        TreeNode* root = new TreeNode(post[index--]);
        int inIndex=0;
        for(int i=start; i<=end; i++){
            if(in[i]==root->val){
                inIndex=i;
                break;
            }
        }
        
        root->right = solve(in, post, inIndex+1, end, index);
        root->left = solve(in, post, start, inIndex-1, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=post.size();
        int index=n-1;
        return solve(in, post, 0, n-1, index);
    }
};