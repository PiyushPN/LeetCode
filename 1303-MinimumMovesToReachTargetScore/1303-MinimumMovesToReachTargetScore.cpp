// Last updated: 18/07/2026, 19:58:55
class Solution {
public:
    int minMoves(int target, int maxD) {
        if(maxD == 0)
        {
            return target-1;
        }
        int ans = 0;
        while(target > 1)
        {
            if(maxD==0)
            {
                return ans+target-1;
            }
            if(maxD > 0 and target%2 == 0)
            {
                ans++;
                target = target/2;
                maxD--;
            }
            else
            {
                --target;
                ans++;
            }
        }
        return ans;
    }
};