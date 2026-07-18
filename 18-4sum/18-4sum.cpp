// Last updated: 18/07/2026, 20:04:30
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n1=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n1-3; i++){
            for(int j=i+1; j<n1-2; j++){
                int m=j+1;
                int n=n1-1;
                while(m<n){
                    long long sum=(long long)nums[i]+nums[j]+nums[m]+nums[n];
                    if(sum==target){
                        ans.push_back({nums[i], nums[m], nums[n], nums[j]});
                        int temp=m, temp1=n;
                        while(m<n and nums[m]==nums[temp]) m++;
                        while(m<n and nums[n]==nums[temp1]) n--;
                    } else if(sum<target){
                        m++;
                    } else {
                        n--;
                    }
                }
                while(j+1<n1 and nums[j]==nums[j+1]) j++;
            }
            while(i+1<n1 and nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};