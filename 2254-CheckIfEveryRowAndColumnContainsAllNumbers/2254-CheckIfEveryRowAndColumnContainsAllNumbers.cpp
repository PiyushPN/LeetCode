// Last updated: 18/07/2026, 19:57:26
class Solution {
public:
    bool checkValid(vector<vector<int>>& arr) {
        int n = arr.size();
        int total = (n*(n+1))/2;
        vector<int> pre, pre1;
        map<int, int> mp1, mp2;
        int sum = 0, sum1 = 0;
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            sum1 = 0;
            for(int j = 0; j < n; j++)
            {
                mp1[arr[i][j]]++;
                mp2[arr[j][i]]++;
                sum+=arr[i][j];
                sum1+=arr[j][i];
            }
            for(auto it: mp1)
            {
                if(it.second>1)
                {
                    return false;
                }
            }
            for(auto it: mp2)
            {
                if(it.second>1)
                {
                    return false;
                }
            }
            mp1.clear();
            mp2.clear();
            pre.push_back(sum);
            pre1.push_back(sum1);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(pre[i] != total or pre1[i] != total)
            {
                return false;
            }
        }
        return true;
    }
};