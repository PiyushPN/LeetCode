// Last updated: 18/07/2026, 20:04:32
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int target=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                } else if(sum<target){
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};