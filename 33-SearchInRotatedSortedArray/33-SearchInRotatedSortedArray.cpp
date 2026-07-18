// Last updated: 18/07/2026, 20:04:19
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[start]<=nums[mid]) {
                if(nums[start]<=target and nums[mid]>=target){
                    end=mid;
                } else {
                    start=mid+1;
                }
            } else {
                if(target>=nums[mid] and target<=nums[end]){
                    start=mid;
                } else {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};