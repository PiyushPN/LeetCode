// Last updated: 18/07/2026, 19:58:01
class Solution {
public:
    bool isValid(string &temp)
    {
        int h = 0, n = temp.size();
        for(int i = 0; i < n; i++)
        {
            if(isdigit(temp[i]))
            {
                return false;
            }
            if(isalpha(temp[i]))
            {
                continue;
            }
            if(temp[i] == '-')
            {
                h++;
                if(h > 1)
                {
                    return false;
                }
                if(i-1<0 or !isalpha(temp[i-1]) or i+1>=n or !isalpha(temp[i+1]))
                {
                    return false;
                }
            }
            else if(i != n-1)
            {
                return false;
            }
        }
        return true;
    }
    int countValidWords(string s) {
        string temp;
        int ans = 0;
        istringstream ss(s);
        while(ss>>temp)
        {
            if(isValid(temp))
            {
                ans++;
            }
        }
        return ans;
    }
};