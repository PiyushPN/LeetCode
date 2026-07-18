// Last updated: 18/07/2026, 19:58:51
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp, mp1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            mp1[i.second]++;
        }
        for(auto i:mp1){
            if(i.second > 1){
                return false;
            }
        }
        return true;
    }
};