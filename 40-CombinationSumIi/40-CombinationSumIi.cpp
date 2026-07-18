// Last updated: 18/07/2026, 20:04:12
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i , int pre, vector<int> &temp, vector<int> &arr, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(i == arr.size() or target < 0)
        {
            return;
        }
        solve(i+1, target, temp, arr, target);
        if(i>0 and arr[i-1] == arr[i] and pre == target) // to deal with duplicates
        {
            return;
        }
        temp.push_back(arr[i]);
        solve(i+1, target, temp, arr, target-arr[i]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> temp;
        sort(arr.begin(), arr.end());
        solve(0, 0, temp, arr, target);
        return ans;
    }
};