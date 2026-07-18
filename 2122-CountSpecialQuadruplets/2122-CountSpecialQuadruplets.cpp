// Last updated: 18/07/2026, 19:58:18
class Solution {
public:
    int countQuadruplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n-3; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                for(int k = j+1; k < n-1; k++)
                {
                    int sum = arr[i]+arr[j]+arr[k];
                    for(int l = k+1; l < n; l++)
                    {
                        if(sum == arr[l])
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};