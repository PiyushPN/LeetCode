// Last updated: 18/07/2026, 19:57:12
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(i%2 != 0)
            {
                odd.push_back(nums[i]);
            }
            else
            {
                even.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        for(int i = 0; i < nums.size(); i++) 
        {
            if(i & 1) 
            {
                nums[i] = odd[0];
                odd.erase(odd.begin());
            }
            else 
            {
                nums[i] = even[0];
                even.erase(even.begin());
            }
        }
        return nums;
        
    }
};