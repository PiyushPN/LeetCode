// Last updated: 18/07/2026, 20:04:10
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int leftmax[n], rightmax[n];
        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];
        int lmax = height[0];
        int rmax = height[n-1];
        for(int i=1; i<n; i++){
            lmax = max(lmax, height[i]);
            leftmax[i] = lmax;
        }
        for(int i=n-2; i>=0; i--){
            rmax = max(rmax, height[i]);
            rightmax[i] = rmax;
        }
        for(int i=0; i<n; i++){
            int temp = min(leftmax[i], rightmax[i])-height[i];
            if(temp>0){
                ans += temp;
            }
        }
        return ans;
    }
};