// Last updated: 18/07/2026, 19:57:00
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long c1 = 0, c2 = 0, ans = 0;
        for(int i = 0; i < text.length(); i++)
        {
            if(text[i] == pattern[1])
            {
                ans+=c1;
                c2++;
            }
            if(text[i] == pattern[0])
            {
                c1++;
            }
            
        }
        return ans+max(c1,c2);            
        
    }
};