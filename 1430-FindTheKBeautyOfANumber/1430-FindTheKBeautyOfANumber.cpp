// Last updated: 18/07/2026, 19:58:40
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for(int i = 0; i <= s.length()-k; i++)
        {
            string temp = s.substr(i,k);
            int div = stoi(temp);
            if(div != 0 and num%div == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};