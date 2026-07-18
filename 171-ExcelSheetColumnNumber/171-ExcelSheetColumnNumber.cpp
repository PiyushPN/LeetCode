// Last updated: 18/07/2026, 20:02:21
class Solution {
public:
    int titleToNumber(string str) {
        int ans = 0;
        for(auto c: str)
        {
            int d = c-'A'+1;
            ans = ans*26+d;
        }
        return ans;
    }
};