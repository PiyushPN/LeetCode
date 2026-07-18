// Last updated: 18/07/2026, 20:03:01
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto num: nums){
            mp[num] = true; 
        }
        for(auto num: nums){
            if(mp.count(num-1) > 0){
                mp[num] = false;
            }
        }
        int ans = 0;
        for(auto num: nums){
            if(mp[num]){
                int j = 0;
                while(mp.count(num+j) > 0){
                    j++;
                }
                ans = max(ans,j);
            }
        }
        return ans;
    }
};