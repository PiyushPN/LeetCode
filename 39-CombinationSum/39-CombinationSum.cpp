// Last updated: 18/07/2026, 20:04:13
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &temp, vector<int> &arr, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0)
        {
            return;
        }
        if(i == arr.size())
        {
            return;
        }
        //solve(i+1, temp, arr, target);
        temp.push_back(arr[i]);
        solve(i, temp, arr, target-arr[i]);
        temp.pop_back();
        solve(i+1, temp, arr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> temp;
        solve(0, temp, arr, target);
        return ans;
        
    }
};