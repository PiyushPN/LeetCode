// Last updated: 18/07/2026, 19:59:47
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>m1(26, 0), m2(26, 0);
        int n=s1.length(), m=s2.length();
        for(int i=0; i<n; i++){
            m1[s1[i]-'a']++;
        }
        int i=0, j=0;
        while(i<m){
            m2[s2[i]-'a']++;
            if(i>=n){
                m2[s2[j++]-'a']--;
            }
            if(m1==m2){
                return true;
            }
            i++;
        }
        return false;
    }
};