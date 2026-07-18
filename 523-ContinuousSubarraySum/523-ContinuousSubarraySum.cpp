// Last updated: 18/07/2026, 19:59:51
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2){
            return false;
        }
        unordered_map<int, int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>1){
                    return true;
                }
            } else {
                mp[sum%k]=i;
            }
        }
        return false;
    }
};