// Last updated: 18/07/2026, 20:00:42
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i<j)
        {
            swap(s[i++], s[j--]);
        }
    }
};