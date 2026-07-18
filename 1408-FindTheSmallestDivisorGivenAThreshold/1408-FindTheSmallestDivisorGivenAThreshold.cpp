// Last updated: 18/07/2026, 19:58:41
class Solution {
public:
    bool solve(int mid,vector<int> &nums,int threshold){
        int total=0;
        for(auto &i:nums){
            total+=i/mid;
            if(i%mid>0){
                total++;
            }
        }
        if(total<=threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,nums,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};