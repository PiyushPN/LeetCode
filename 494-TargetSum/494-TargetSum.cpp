// Last updated: 18/07/2026, 19:59:56
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int Array_sum = 0;
        int sum;
        for(int i = 0; i < n; i++)
        {
            Array_sum += nums[i];
        }
        if(Array_sum < abs(target) || (target+Array_sum) %2 != 0)
        {
            return 0;
        }
        sum = (target+Array_sum)/2;
        int t[n+1][sum+1];
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                if(i == 0)
                {
                    t[i][j] = 0;
                }
                if(j == 0)
                {
                    t[i][j] = 1;
                }
            }
        }
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
       
        return t[n][sum];
    }
};