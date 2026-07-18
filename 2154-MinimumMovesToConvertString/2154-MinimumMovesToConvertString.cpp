// Last updated: 18/07/2026, 19:58:06
class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        int n = s.length();
        int i = 0;
        while(i < n)
        {
            if(s[i] == 'O')
            {
                i++;
            }
            else
            {
                ans++;
                i+=3;
            }
                
        }
        return ans;
    }
};