// Last updated: 18/07/2026, 19:57:23
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        int count = 0;
        string temp = "";
        for(int i = 0; i < n; i++)
        {
            temp += s[i];
            count++;
            if(count == k)
            {
                ans.push_back(temp);
                temp = "";
                count = 0;
            }
        }
        if(count == 0)
        {
            return ans;
        }
        while(count != k)
        {
            temp+=fill;
            count++;
        }
        ans.push_back(temp);
        return ans;
            
        
    }
};