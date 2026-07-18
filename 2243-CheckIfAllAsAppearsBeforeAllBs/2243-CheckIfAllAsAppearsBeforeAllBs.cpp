// Last updated: 18/07/2026, 19:57:30
class Solution {
public:
    bool checkString(string s) {
        
        for(int i = 0; i < s.length()-1; i++)
        {
           if(s[i]=='b' && s[i+1]=='a')
              return false;

        }
        return true;
        
    }
};