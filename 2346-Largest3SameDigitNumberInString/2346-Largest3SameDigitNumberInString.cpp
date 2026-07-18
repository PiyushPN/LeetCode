// Last updated: 18/07/2026, 19:56:46
class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int temp[10] = {0};
        string ans = "";
        for(int i = 0; i < num.length()-2; i++)
        {
            if(num[i] == num[i+1] and num[i] == num[i+2])
            {
                temp[num[i]-'0']++;
            }
        }
        for(int i = 9; i >= 0; i--)
        {
            if(temp[i]> 0)
            {
                ans += i+'0';
                ans += i+'0';
                ans += i+'0';
                break;
            }
        }
        return ans;
    }
};