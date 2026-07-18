// Last updated: 18/07/2026, 20:00:37
class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
            {
                vowel += s[i];
            }
        }
        int j = vowel.length()-1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
            {
                s[i] = vowel[j--];
            }
        }
        return s;
    }
};