// Last updated: 18/07/2026, 19:57:52
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1, end = *max_element(quantities.begin(), quantities.end());
        int ans = end;
        
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            int c = 0;
            for(int i = 0; i < quantities.size(); i++)
            {
                c += quantities[i]/mid; 
                if(quantities[i]%mid != 0)
                {
                    c++;
                }
            }
            if(c <= n)
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
        
    }
};