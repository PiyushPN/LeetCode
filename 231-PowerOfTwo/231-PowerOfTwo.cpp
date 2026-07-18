// Last updated: 18/07/2026, 20:01:28
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 and __builtin_popcount(n)==1;
    }
};