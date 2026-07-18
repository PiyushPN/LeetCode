// Last updated: 18/07/2026, 20:03:04
class Solution {
public:
    bool isPalindrome(string str) {
        string tmp="";
        for(auto s: str){
            if((s>=65 and s<=90) or (s>=97 and s<=122) or (s>=48 and s<=57)){
                tmp+=char(tolower(s));
            }
        }
        if(equal(tmp.begin(), tmp.begin()+tmp.length()/2, tmp.rbegin())){
            return true;
        }
        return false;
    }
};