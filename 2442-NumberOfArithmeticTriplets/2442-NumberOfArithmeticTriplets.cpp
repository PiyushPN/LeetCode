// Last updated: 18/07/2026, 19:56:32
class Solution {
public:
    int arithmeticTriplets(vector<int>& arr, int diff) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j<n-1; j++)
            {
                int d = arr[j]-arr[i];
                if(d!=diff)
                {
                    continue;
                }
                else
                {
                    int k = j+1;
                    while(k<n)
                    {
                        if(arr[k]-arr[j]==diff)
                        {
                            ans++;
                        }
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};