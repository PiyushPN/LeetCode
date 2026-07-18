// Last updated: 18/07/2026, 19:58:22
class Solution {
public:
    void solve(int index, int k, int &ans, vector<int> &v)
    {
        if(v.size() == 1)
        {
            ans = v[0];
            return;
        }
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        solve(index, k, ans, v);
    }
    int findTheWinner(int n, int k) {
        int ans = -1;
        int index = 0;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back(i+1);
        }
        solve(index, k-1, ans, v);
        return ans;
    }
};