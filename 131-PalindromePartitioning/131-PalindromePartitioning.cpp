// Last updated: 18/07/2026, 20:02:58
class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int index, string s, vector<vector<string>> &ans, vector<string> &temp, int n){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(i+1, s, ans, temp, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> temp;
        solve(0, s, ans, temp, n);
        return ans;
    }
};