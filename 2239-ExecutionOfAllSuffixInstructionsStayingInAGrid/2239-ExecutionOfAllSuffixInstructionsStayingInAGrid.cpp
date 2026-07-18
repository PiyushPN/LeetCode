// Last updated: 18/07/2026, 19:57:31
class Solution {
public:
    int solve(int i, int j, string s, int n)
    {
        int count = 0;
        for(int k = 0; k < s.length(); k++)
        {
            
            if(s[k] == 'R')
            {
                
                j++;
            }
            else if(s[k] == 'L')
            {
                j--;
            }
            else if(s[k] == 'U')
            {
                i--;
            }
            else
            {
                i++;
            }
            if(i<0 || j<0 || i>=n || j>=n)
            {
                return count;
            }
            count++;
        }
        return count;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for(int i = 0; i < s.length(); i++)
        {
            int count = 0;
            //cout<<s.substr(i)<<endl;
            count = solve(startPos[0], startPos[1], s.substr(i), n);
            ans.push_back(count);
        }
        return ans;
    }
};