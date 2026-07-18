// Last updated: 18/07/2026, 19:57:41
class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        int red[10] = {0};
        int green[10] = {0};
        int blue[10] = {0};
        int ans = 0;
        for(int i = 0; i < n; i+=2)
        {
            if(rings[i]=='R')
            {
                red[rings[i+1]-'0']=1;
            }
            else if(rings[i]=='B')
            {
                blue[rings[i+1]-'0']=2;
            }
            else if(rings[i]=='G')
            {
                green[rings[i+1]-'0']=1;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            if(red[i] and green[i] and blue[i])
            {
                ans++;
            }
        }
        return ans;
    }
};