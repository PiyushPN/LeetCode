// Last updated: 18/07/2026, 20:01:02
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            int n1 = words[i].length();
            for(int k = 0; k < n1; k++)
            {
                mp[words[i][k]] = 0;
            }
            for(int j = i+1; j < n; j++)
            {
                int flag = 1;
                int n2 = words[j].length();
                for(int k = 0; k < n2; k++)
                {
                    if(mp.find(words[j][k]) != mp.end())
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    int temp = n1*n2;
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};