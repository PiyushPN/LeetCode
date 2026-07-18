// Last updated: 18/07/2026, 19:57:18
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batt) {
        long long sum = accumulate(batt.begin(), batt.end(), (long long)0);
        sort(batt.begin(), batt.end());
        while(batt.back()>sum/n)
        {
            sum -= batt.back();
            batt.pop_back();
            n--;
        }
        return sum/n;
    }
};