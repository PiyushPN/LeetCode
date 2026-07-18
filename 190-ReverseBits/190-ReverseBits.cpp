// Last updated: 18/07/2026, 20:02:06
class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0; i<32; i++){
            ans<<=1;
            ans |= (n&1);
            n>>=1;
        }
        return ans;
    }
};