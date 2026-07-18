// Last updated: 18/07/2026, 20:00:02
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        unordered_map<char, int> mp;
        int n = s.length();
        int ans = 0;
        int mx = 0;
        while(i<n){
            mp[s[i]]++;
            mx = max(mx, mp[s[i]]);
            if((i-j+1)-mx > k){
                mp[s[j]]--;
                j++;
            }
            else{
                ans = max(ans, i-j+1);
            }
            i++;
        }
        return ans;
    }
};