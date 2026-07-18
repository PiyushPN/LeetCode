// Last updated: 18/07/2026, 19:56:59
class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        priority_queue<float> pq;
        long double sum = 0, ans = 0, half = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            sum += nums[i];
        }
        half = sum/2;
        while(sum > half)
        {
            long double temp = pq.top();
            pq.pop();
            temp = temp/2;
            half+=temp;
            pq.push(temp);
            ans++;
        }
        return ans;
    }
};