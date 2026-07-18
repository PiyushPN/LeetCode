// Last updated: 18/07/2026, 20:01:07
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int size=0;
        for(int i=1; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            } else {
                int ind=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};