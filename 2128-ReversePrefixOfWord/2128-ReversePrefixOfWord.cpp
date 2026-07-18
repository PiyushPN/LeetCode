// Last updated: 18/07/2026, 19:58:15
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int index = -1;
        for(int i = 0; i < n; i++)
        {
            if(word[i] == ch)
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            return word;
        }
        
        // reverse(word.begin(), word.end()-index);
        int start = 0, end = index;
        while(start < end)
        {
            swap(word[start], word[end]);
            start++, end--;
        }
        return word;
    }
};