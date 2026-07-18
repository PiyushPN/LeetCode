// Last updated: 18/07/2026, 19:57:06
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int flag = 0;
       
        for(int i = 0; i < words.size(); i++)
        {
            flag = 0;
            for(int j = 0; j < pref.size(); j++)
            {
                if(pref[j] != words[i][j])
                {
                    flag = 1;
                    break;
                }
               
            }
            if(flag == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};