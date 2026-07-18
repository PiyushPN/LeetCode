// Last updated: 18/07/2026, 19:58:00
class Solution {
public:
    bool solve(int i)
    {
        vector<int> v(10);
        while(i>0)
        {
            int rem = i%10;
            if(rem == 0)
            {
                return false;
            }
            v[rem]++;
            i = i/10;
        }
        for(int j = 1; j < 10; j++)
        {
            if(v[j] and j != v[j])
            {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        
        int flag = 0;
        int ans = 0;
        for(int i = n+1; i <= 1e7; i++)
        {
            if(solve(i))
            {
                return i;
            }
        }
        return 0;
    }
};