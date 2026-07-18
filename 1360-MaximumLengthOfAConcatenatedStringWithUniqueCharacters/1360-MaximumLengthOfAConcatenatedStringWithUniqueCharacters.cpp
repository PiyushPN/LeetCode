// Last updated: 18/07/2026, 19:58:44
class Solution {
public:
    int ans = 0;
    bool is_unique(string str){
        int n = str.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[str[i]]++;
            if(mp[str[i]]>1){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> arr, int i, int n, string curr){
        if(!is_unique(curr)){
            return;
        }
        if(i==n){
            int size = curr.size();
            ans = max(ans, size);
            return;
        }
        solve(arr, i+1, n, curr+arr[i]);
        solve(arr, i+1, n, curr);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        solve(arr, 0, n, "");
        return ans;
    }
};