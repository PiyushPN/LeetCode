// Last updated: 18/07/2026, 20:04:35
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n = height.size();
        int i=0, j=n-1;
        while(i<j){
            int temp = min(height[i], height[j])*(j-i);
            ans = max(ans, temp);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};