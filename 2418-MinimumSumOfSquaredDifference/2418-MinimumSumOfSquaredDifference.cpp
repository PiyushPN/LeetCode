// Last updated: 18/07/2026, 19:56:39
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        vector<int> diff(1e5+1);
        for(int i = 0; i < nums1.size(); i++)
        {
            diff[abs(nums1[i]-nums2[i])]++;
        }
        int k = k1+k2;
        for(int i = 1e5; i>=0; i--)
        {
            int cnt = diff[i];
            if(cnt <= k)
            {
                if(i<=1)
                {
                    return 0;
                }
                diff[i]=0;
                diff[i-1] += cnt;
                k -= cnt;
            }
            else
            {
                if(i==0)
                {
                    return 0;
                }
                diff[i]-= k;
                diff[i-1] += k;
                break;
                
            }
        }
         long long ans = 0;
        for(int i = 0; i <= 1e5; i++)
        {
            ans += (long long)diff[i] * ((long long)i*i);
        }
        return ans;
    }
};