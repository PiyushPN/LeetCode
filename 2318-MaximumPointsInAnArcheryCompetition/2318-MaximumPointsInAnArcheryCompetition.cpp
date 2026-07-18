// Last updated: 18/07/2026, 19:56:55
class Solution {
public:
    vector<int> ans;
    int mx;
    void solve(vector<int> &bob, vector<int> &alice, int i, int num, int score)
    {
        if(i==-1 or num<=0)
        {
            if(score>mx)
            {
                ans = bob;
                mx = score;
            }
            return ;
        }
        solve(bob, alice, i-1, num, score);
        if(num>alice[i])
        {
            bob[i] = alice[i]+1;
            num -= (alice[i]+1);
            score += i;
            solve(bob, alice, i-1, num, score);
            bob[i] = 0;
        }
        return ;
    }
    vector<int> maximumBobPoints(int num, vector<int>& alice) {
        int n = alice.size();
        mx = INT_MIN;
        vector<int> bob(12, 0);
        solve(bob, alice, 11, num, 0);
        int arrow_used = 0;
        for(auto it: ans)
        {
            arrow_used += it;
        }
        if(arrow_used < num)
        {
            ans[0] += (num-arrow_used);
        }
        return ans;
            
    }
};