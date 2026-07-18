// Last updated: 18/07/2026, 19:57:54
class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        {
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
        set<char> s;
        int ans = 0;
        int n = word.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isVowel(word[j]))
                {
                    s.insert(word[j]);
                }
                else
                {
                    break;
                }
                if(s.size() == 5)
                {
                    ans++;
                }
                    
            }
            s.clear();
        }
        return ans;
        
    }
};