// Last updated: 18/07/2026, 20:04:36
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1){
            return s;
        }
        string ans="";
        for(int i=1; i<n; i++){
            int l=i;
            int h=i;
            while(l>=0 and h<n and s[l]==s[h]){
                l--, h++;
            }
            string tmp=s.substr(l+1, h-l-1);
            if(ans.length()<tmp.length()){
                ans=tmp;
            }
            l=i-1;
            h=i;
            while(l>=0 and h<n and s[l]==s[h]){
                l--, h++;
            }
            tmp=s.substr(l+1, h-l-1);
            if(ans.length()<tmp.length()){
                ans=tmp;
            }
        }
        return ans;
    }
};