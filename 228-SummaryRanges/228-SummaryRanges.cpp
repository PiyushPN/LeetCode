// Last updated: 18/07/2026, 20:01:32
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        vector<string> ans;
        if(n==0)
        {
            return ans;
        }
        if(n == 1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        string temp = "";
        while(j<n)
        {
            temp = "";
            while(j<n and nums[j-1]+1 == nums[j])
            {
                j++;
            }
            if(nums[i] == nums[j-1])
            {
                temp += to_string(nums[i]);
            }
            else
            {
                temp += to_string(nums[i]);
                temp += '-';
                temp += '>';
                temp += to_string(nums[j-1]);
            }
            ans.push_back(temp);
            i = j;
            j++;
            if(j == n)
            {
                temp = "";
                if(nums[i] == nums[j-1])
                {
                    temp += to_string(nums[i]);
                }
                else
                {
                    temp += to_string(nums[i]);
                    temp += '-';
                    temp += '>';
                    temp += to_string(nums[j-1]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};