// Last updated: 18/07/2026, 19:58:19
class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length();
        if(n!=m)
        {
            return n<m;
        }
        else
        {
            return s1 < s2;
        }
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), comp);
        return nums[n-k];
    }
};