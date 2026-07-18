// Last updated: 18/07/2026, 20:02:00
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while(left != right)
        {
            left>>=1;
            right>>=1;
            cnt++;
        }
        left<<=cnt;
        return left;
    }
};