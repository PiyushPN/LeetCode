// Last updated: 18/07/2026, 20:02:16
class Solution {
public:
    static bool comp(string &s1 , string &s2)
    {
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        string ans = "";
        for(auto num: nums)
        {
            str.push_back(to_string(num));
        }
        sort(str.begin(), str.end(), comp);
        for(auto i: str)
        {
            ans += i;
        }
        while(ans[0] == '0' and ans.size() > 1)
        {
            ans = ans.substr(1);
        }
        return ans;
    }
};