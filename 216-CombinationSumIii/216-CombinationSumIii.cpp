// Last updated: 18/07/2026, 20:01:43
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k, int n, vector<int> &temp, int num)
    {
        if(k==0 and n==0)
        {
            ans.push_back(temp);
            return;
        }
        if(num > 9)
        {
            return;
        }
        temp.push_back(num);
        solve(k-1, n-num, temp, num+1);
        temp.pop_back();
        solve(k, n, temp, num+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k, n, temp, 1);
        return ans;
    }
};