// Last updated: 18/07/2026, 20:01:09
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void buildString(TreeNode* root, string &tree){
        if(!root){
            tree += "null,";
            return;
        }
        tree += to_string(root->val)+",";
        buildString(root->left, tree);
        buildString(root->right, tree);
    }
    string serialize(TreeNode* root) {
        string tree="";
        buildString(root, tree);
        return tree;
        
    }

    TreeNode *buildTree(queue<string> &q){
        string s = q.front();
        q.pop();
        if(s=="null"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = "";
        queue<string> q;
        for(char c: data){
            if(c==','){
                q.push(s);
                s="";
            }
            else{
                s+=c;
            }
        }
        return buildTree(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));