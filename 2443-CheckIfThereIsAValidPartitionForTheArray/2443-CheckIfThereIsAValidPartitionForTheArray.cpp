// Last updated: 18/07/2026, 19:56:30
int dp[100005];
class Solution {
public:
    
    bool solve(int i, vector<int> &arr, int n)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        if(i+1<n and arr[i] == arr[i+1])
        {
            if(solve(i+2, arr, n))
            {
                return dp[i] = true;
            }
            if(i+2<n and arr[i]==arr[i+2])
            {
                if(solve(i+3, arr, n))
                {
                    return dp[i]=true;
                }
            } 
        }
        if(i+2<n and arr[i+1]-arr[i]==1 and arr[i+2]-arr[i+1]==1)
        {
            if(solve(i+3, arr, n))
            {
                return dp[i]=true;
            }
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, nums, n);
    }
};