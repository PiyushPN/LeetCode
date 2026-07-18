// Last updated: 18/07/2026, 20:01:55
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, false);
        int ans = 0;
        for(int i = 2; i < n; i++)
        {
            if(sieve[i])
            {
                continue;
            }
            ans++;
            for(long long j = (long long)i*i; j < n; j+=i)
            {
                sieve[j]=true;
            }
        }
        return ans;
    }
};