// Last updated: 18/07/2026, 20:03:52
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> a(n),b(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    a[i]=1;
                    b[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==1 or b[j]==1){
                    mat[i][j]=0;
                }
            }
        }
    }
};