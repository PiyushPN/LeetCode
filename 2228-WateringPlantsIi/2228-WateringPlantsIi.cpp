// Last updated: 18/07/2026, 19:57:38
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int i = 0, j = plants.size()-1;
        int A = capacityA, B = capacityB;
        while(i<=j)
        {
            if(i==j)
            {
                if(A >= B)
                {
                    if(A < plants[i])
                    {
                        ans++;
                        A=capacityA;
                        A-=plants[i];
                    }
                    else
                    {
                        A-=plants[i];
                    }
                }
                else
                {
                    if(B < plants[j])
                    {
                        ans++;
                        B=capacityB;
                        B-=plants[j];
                    }
                    else
                    {
                        B-=plants[j];
                    }
                }
            }
            else
            {
                if(A < plants[i])
                {
                    ans++;
                    A=capacityA;
                    A-=plants[i];
                }
                else
                {
                    A-=plants[i];
                }
                if(B < plants[j])
                {
                    ans++;
                    B=capacityB;
                    B-=plants[j];
                }
                else
                {
                    B-=plants[j];
                }
            }
            i++, j--;       
        }
        return ans;
    }
};