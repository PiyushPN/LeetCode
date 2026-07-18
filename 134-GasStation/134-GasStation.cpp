// Last updated: 18/07/2026, 20:02:54
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        int total_fuel = accumulate(gas.begin(), gas.end(), 0);
        int n = gas.size();
        if(total_cost > total_fuel)
        {
            return -1;
        }
        int curr_fuel = 0, start = 0;
        for(int i = 0; i < n; i++)
        {
            if(curr_fuel < 0)
            {
                start = i;
                curr_fuel = 0;
            }
            curr_fuel += gas[i]-cost[i];
        }
        return start;
    }
};