// Last updated: 18/07/2026, 19:57:56
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> vis(1001, false);
        queue<int> q;
        q.push(start);
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front();
                q.pop();
                if(x == goal)
                {
                    return ans;
                }
                if(x > 1000 or x < 0 or vis[x])
                {
                    continue;
                }
                vis[x] = true;
                for(int i = 0; i < nums.size(); i++)
                {
                    int a = x+nums[i];
                    int b  = x-nums[i];
                    int c = x^nums[i];
                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }
            ans++;
        }
        return -1;
        
    }
};