// Last updated: 18/07/2026, 19:56:49
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        //int ans = 0;
        int n = nums.size();
        set<string> s1;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            string temp = "";
            int count = 0;
            for(int j = i; j < n; j++)
            {
                
                if(nums[j]%p == 0)
                {
                    count++;
                }
                if(count > k)
                {
                    break;
                }
                temp += to_string(nums[j])+'$';
                s1.insert(temp);
            }
      }
     
        return s1.size();
    }
};