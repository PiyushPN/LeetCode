// Last updated: 18/07/2026, 19:56:52
class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> s;
        string temp = number;
        for(int i = 0; i < number.length(); i++)
        {
            if(temp[i] == digit)
            {
                temp.erase(i, 1);
                s.push_back(temp);
            }
            temp = number;
        }
        sort(s.begin(), s.end());
        int len = s.size();
        return s[len-1];
        
    }
};