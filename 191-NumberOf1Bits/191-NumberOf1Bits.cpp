// Last updated: 18/07/2026, 20:02:05
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
        
    }
};