// Last updated: 18/07/2026, 19:59:11
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long> last(26);
        int mod = 1e9+7;
        for(auto ch: s)
        {
            last[ch-97] = accumulate(last.begin(), last.end(), 1L) % mod;
        }
        return accumulate(last.begin(), last.end(), 0L) % mod;
    }
};