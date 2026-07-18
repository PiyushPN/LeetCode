// Last updated: 18/07/2026, 20:02:24
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        char temp;
        while(n)
        {
            n-=1;
            temp = 'A'+n%26;
            ans = temp + ans;
            n/=26;
        }
        return ans;
    }
};