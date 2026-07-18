// Last updated: 18/07/2026, 20:00:16
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        unordered_set<char> st;
        for(auto i:mp){
            if(i.second==1){
                st.insert(i.first);
            }
        }
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end())
                return i;
        }
        return -1;
        // int n = s.length();
        // unordered_map<char, pair<int, int>> mp;
        // for(int i = 0; i < n; i++)
        // {
        //     mp[s[i]].first = i;
        //     mp[s[i]].second++;
        // }
        // for(auto it: mp)
        // {
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        // int ans = INT_MAX;
        // for(int i = 0; i < n; i++)
        // {
        //     if(mp[s[i]].second > 1)
        //     {
        //         mp.erase(s[i]);
        //     }
        // }
        // for(auto it: mp)
        // {
        //     ans = min(ans, it.second.first);
        // }
        // if(ans == INT_MAX)
        // {
        //     return -1;
        // }
        // return ans;
    }
};