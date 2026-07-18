// Last updated: 18/07/2026, 20:01:49
class TrieNode{
    public:
    vector<TrieNode*> vec;
    bool flag;
    TrieNode(){
        vec=vector<TrieNode*>(26);
        flag=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tri=root;
        for(auto i:word){
            if(!tri->vec[i-97]){
                tri->vec[i-97]=new TrieNode();
            }
            tri=tri->vec[i-97];
        }
        tri->flag=true;
    }
    
    bool search(string word) {
        TrieNode* tri=root;
        for(auto i:word){
            if(!tri->vec[i-97]){
                return false;
            }
            tri=tri->vec[i-97];
        }
        return tri->flag;
    }
    
    bool startsWith(string word) {
        TrieNode* tri=root;
        for(auto i:word){
            if(!tri->vec[i-97]){
                return false;
            }
            tri=tri->vec[i-97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */