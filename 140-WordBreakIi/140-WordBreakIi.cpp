// Last updated: 18/07/2026, 20:02:47
class Solution {
public:
    void solve(string s, vector<string>& dict, string temp, vector<string> &ans){
        if(s.length() == 0){
            temp.erase(temp.begin()+temp.length()-1);
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<s.length(); i++){
            string left = s.substr(0, i+1);
            if(find(dict.begin(), dict.end(), left) != dict.end()){
                string right = s.substr(i+1);
                solve(right, dict, temp+left+" ", ans);
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict){
        vector<string> ans;
        string temp = "";
        solve(s, wordDict, temp, ans);
        return ans;
    }
};