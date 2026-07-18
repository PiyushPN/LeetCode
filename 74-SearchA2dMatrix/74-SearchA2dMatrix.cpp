// Last updated: 18/07/2026, 20:03:51
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start=0, end=m*n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int mid_val = matrix[mid/n][mid%n];
            if(mid_val==target){
                return true;
            }
            else if(mid_val<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};