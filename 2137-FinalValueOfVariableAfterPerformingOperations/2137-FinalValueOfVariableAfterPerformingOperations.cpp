// Last updated: 18/07/2026, 19:58:11
class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int n = op.size();
        int add = 0, sub = 0;
        for(int i = 0; i < n; i++)
        {
            if(op[i][0] == '+' || op[i][1] == '+')
            {
                add++;
            }
            else
            {
                sub++;
            }
        }
        return add-sub;
    }
};