// Last updated: 18/07/2026, 19:56:56
class Solution {
public:
    int countCollisions(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> pre(n, 0);
        for(int i = 1; i < n; i++)
        {
            if(s[i] == 'R' and s[i-1] == 'R')
            {
                pre[i] = pre[i-1]+1;
            }
        }
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == 'R' and s[i+1] == 'L')
            {
                ans += 2;
                ans += pre[i];
                s[i] = 'S';
                s[i+1] = 'S';
            }
            else if(s[i] == 'S' and s[i+1] == 'L')
            {
                ans += 1;
                s[i+1] = 'S';
            }  
            else if(s[i] == 'R' and s[i+1] == 'S')
            {
                ans += 1;
                ans += pre[i];
                s[i] = 'S';
            }
        }
        return ans;
    }
};