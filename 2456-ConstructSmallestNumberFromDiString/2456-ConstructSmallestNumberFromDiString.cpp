// Last updated: 18/07/2026, 19:56:25
class Solution {
public:
    bool solve(int ind, string temp, string pattern, vector<bool> &vis, string &ans)
    {
        if(ind==pattern.length())
        {
            ans = temp;
            return true;
        }
        if(pattern[ind] == 'D')
        {
            int val = temp.back()-'0';
            for(int i = 1; i<val; i++)
            {
                if(vis[i]==0)
                {
                    vis[i] = true;
                    if(solve(ind+1, temp+to_string(i), pattern, vis, ans))
                    {
                        return true;
                    }
                    vis[i] = false;
                }
            }
            return false;
        }
        else
        {
            int val = temp.back()-'0';
            for(int i = val+1; i<=9; i++)
            {
                if(vis[i] == 0)
                {
                    vis[i] = true;
                    if(solve(ind+1, temp+to_string(i), pattern, vis, ans))
                    {
                        return true;
                    }
                    vis[i]=false;
                }
            }
            return false;
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> vis(10, 0);
        for(int i = 1; i <= 9; i++)
        {
            string ans = "";
            vis[i] = true;
            if(solve(0, to_string(i), pattern, vis, ans))
            {
                return ans;
            }
            vis[i] = false;
        }
        return "";
    }
};