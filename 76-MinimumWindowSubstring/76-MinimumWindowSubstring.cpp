// Last updated: 18/07/2026, 20:03:48
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int count = t.length();
        int n = s.length();
        for(char c: t){
            map[c]++;
        }
        int minLen=INT_MAX, start=0;
        int i=0, j=0;
        while(j<n){
            if(map[s[j++]]-- > 0){
                count--;
            }
            while(count == 0){
                if(j-i<minLen){
                    start=i;
                    minLen=j-i;
                }
                if(map[s[i++]]++ == 0){
                    count++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};