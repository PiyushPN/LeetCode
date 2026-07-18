// Last updated: 18/07/2026, 19:57:04
class Solution {
public:
    bool solve(int num)
    {
        int sum = 0;
        while(num)
        {
            int rem = num%10;
            sum+=rem;
            num=num/10;
        }
        if(sum%2==0)
        {
            return true;
        }
        return false;
    }
    int countEven(int num) {
        int ans = 0;
        for(int i = num; i>=1; i--)
        {
            if(solve(i))
            {
                ans++;
            }
        }
        return ans;
        
    }
};