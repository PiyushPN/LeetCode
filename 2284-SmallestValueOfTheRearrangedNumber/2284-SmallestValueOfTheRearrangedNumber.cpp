// Last updated: 18/07/2026, 19:57:10
class Solution {
public:
    long long smallestNumber(long long num) {
        if(num <= 10 && num >= 0)
        {
            return num;
        }
        vector<long long> digit;
        long long ans = 0;
        
        if(num>0)
        {
            while(num)
            {
                long long rem = num%10;
                digit.push_back(rem);
                num = num/10;
            }
            sort(digit.begin(), digit.end());
            if(digit[0] == 0)
            {
                for(long long i = 0; i < digit.size(); i++)
                {
                    if(digit[i])
                    {
                        swap(digit[0], digit[i]);
                        break;
                    }
                }
            }
            for(long long i=0;i<digit.size();i++)
            {
                ans=ans*10+digit[i];
            }
        }
        else
        {
            num*=-1;
            while(num)
            {
                long long rem = num%10;
                digit.push_back(rem);
                num = num/10;
            }
            sort(digit.begin(), digit.end(), greater<long long>());
            if(digit[0] == 0)
            {
                for(long long i = 0; i < digit.size(); i++)
                {
                    if(digit[i])
                    {
                        swap(digit[0], digit[i]);
                        break;
                    }
                }
            }
            for(long long i=0;i<digit.size();i++)
            {
                ans=ans*10+digit[i];
            }
            ans*=-1;
        }
        return ans;    
        
    }
};