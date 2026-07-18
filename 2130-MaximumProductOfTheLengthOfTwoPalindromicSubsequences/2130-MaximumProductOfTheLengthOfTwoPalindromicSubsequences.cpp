// Last updated: 18/07/2026, 19:58:13
class Solution {
public:
    int ans = INT_MIN;
    void solve(string s, string &p1, string &p2)
    {
        //cout<<p1<<" "<<p2<<endl;
        if(s.length() == 0)
        {
            if(equal(p1.begin(), p1.begin()+p1.size()/2, p1.rbegin()) and equal(p2.begin(), p2.begin()+p2.size()/2, p2.rbegin()))
            {
                int temp = p1.size()*p2.size();
                ans = max(ans, temp);
            }
            return;
        }
        p1.push_back(s[0]);
        solve(s.substr(1), p1, p2);
        p1.pop_back();
        p2.push_back(s[0]);
        solve(s.substr(1), p1, p2);
        p2.pop_back();
        solve(s.substr(1), p1, p2);
        return;
        
    }
    int maxProduct(string s) {
        string p1 = "", p2 = "";
        solve(s, p1, p2);
        return ans;
        
    }
};