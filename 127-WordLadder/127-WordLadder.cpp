// Last updated: 18/07/2026, 20:03:03
class Solution {
public:
    bool createadjandcheck(string word, string word1, unordered_map<string, vector<string>> &adj){
        if(word.length()!=word1.length()){
            return false;
        }
        int n = word.length();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(word[i]!=word1[i]){
                cnt++;
            }
        }
        if(cnt>1){
            return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map<string, vector<string>> adj;
        int flag=0;
        for(int i=0; i<n; i++){
            if(wordList[i]==endWord){
                flag=1;
            }
            if(createadjandcheck(beginWord, wordList[i], adj)){
                adj[beginWord].push_back(wordList[i]);
            }
        }
        if(flag==0 or adj.size()==0){
            return 0;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(createadjandcheck(wordList[i], wordList[j], adj)){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, bool> vis;
        unordered_map<string, int> level;
        vis[beginWord]=true;
        level[beginWord]=1;
        while(!q.empty()){
            string temp=q.front();
            q.pop();
            for(auto str: adj[temp]){
                if(vis.find(str)==vis.end()){
                    q.push(str);
                    vis[str]=true;
                    level[str]=level[temp]+1;
                }
            }
        } 
        return level[endWord];
    }
};