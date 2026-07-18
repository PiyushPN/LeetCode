// Last updated: 18/07/2026, 19:57:58
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(i%10 == nums[i])
            {
                return i;
            }
        }
        return -1;
        
    }
};