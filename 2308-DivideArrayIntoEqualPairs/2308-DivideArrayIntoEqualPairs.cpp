// Last updated: 18/07/2026, 19:57:01
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int a[501] = {0};
        for(int i = 0; i < nums.size(); i++)
        {
            a[nums[i]]++;
        }
        for(int i = 0; i < 501; i++)
        {
            if(a[i] % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};