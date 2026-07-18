// Last updated: 18/07/2026, 20:04:15
class Solution {
public:
    string countAndSay(int n) 
    {
        int i = 2;
        string ans = "1";
        while(i<=n)
        {
            string temp = "";
            char c = ans[0];
            int count = 0;
            for(int j = 0; j < ans.size(); j++)
            {
                if(ans[j] == c)
                {
                    count++;
                }
                else
                {
                    temp+=to_string(count);
                    temp+=c;
                    c = ans[j];
                    count=1;
                }
                
            }
            temp+=to_string(count);
            temp+=c;
            ans = temp;
            i++;
        }
        return ans;
    }
};