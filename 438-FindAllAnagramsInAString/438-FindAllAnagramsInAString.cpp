// Last updated: 18/07/2026, 20:00:00
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int win=p.length();
        int n=s.length();
        unordered_map<char, int> mp;
        vector<int> ans;
        for(int i=0; i<win; i++){
            mp[p[i]]++;
        }
        int i=0, j=0, count=mp.size();
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(j-i+1<win){
                j++;
            } else if(j-i+1==win){
                if(count==0){
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++, j++;
            }
        }
        return ans;
    }
};