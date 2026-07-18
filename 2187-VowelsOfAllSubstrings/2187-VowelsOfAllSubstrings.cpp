// Last updated: 18/07/2026, 19:57:53
class Solution {
public:
    
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            if(string("aeiou").find(word[i]) != string::npos)
            {
                ans += (long long)(i+1)*(n-i);
            }
        }
        return ans;
        
    }
};