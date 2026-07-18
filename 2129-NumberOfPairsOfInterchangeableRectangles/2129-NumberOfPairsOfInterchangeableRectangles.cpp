// Last updated: 18/07/2026, 19:58:14
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) 
    {
        long long ans = 0;
        int n=r.size();
        unordered_map<double, int> mp;
        for(int i = 0; i < n; i++)
        {
            int a = r[i].front(), b = r[i].back();
            double div = (double)a/b;
            mp[div]++;
        }
        for(auto i: mp)
        {
             int n1 = i.second;
             n1 = n1-1;
             cout<<i.first<<" "<<i.second<<endl;
             if(n1 != 0)
             {
                 long long product = 0;
                 while(n1)
                 {
                    product += n1;
                     n1--;
                 }
                 ans+=product;
             }
        }
        // for(int i = 0; i < n-1; i++)
        // {
        //     int a = r[i].front(), b = r[i].back();
        //     double div = (double)a/b;
        //     for(int j = i+1; j < n; j++)
        //     {
        //         int c = r[j].front(), d = r[j].back();
        //         double div1 = (double)c/d;
        //         if(div == div1)
        //         {
        //             ans++;
        //         }
        //     }
        // }
         return ans;
    }
};