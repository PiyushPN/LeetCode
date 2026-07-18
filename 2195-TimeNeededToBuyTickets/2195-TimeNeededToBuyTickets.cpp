// Last updated: 18/07/2026, 19:57:51
class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        while(true)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i] > 0)
                {
                    ans++;
                    arr[i]--;
                }
                if(arr[k] == 0)
                {
                    return ans;
                }
            }
        }
        
    }
};