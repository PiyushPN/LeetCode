// Last updated: 18/07/2026, 20:03:58
class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i <= n; i++)
        {
            str += i+'0';
        }
        while(--k)
        {
            next_permutation(str.begin(), str.end());
        }
        return str;
    }
};