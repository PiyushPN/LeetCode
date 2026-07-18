// Last updated: 18/07/2026, 19:58:27
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        long long ans = 0;
        int even = 0;
        int odd = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum+=arr[i];
            if(sum%2==0)
            {
                ans += odd;
                even++;
            }
            else
            {
                ans += even+1;
                odd++;
            }
        }
        return ans%1000000007;
    }
};