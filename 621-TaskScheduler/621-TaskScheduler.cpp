// Last updated: 18/07/2026, 19:59:43
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> pq;
        unordered_map<char, int> mp;
        for(auto task: tasks){
            mp[task]++;
        }
        for(auto ele: mp){
            pq.push(ele.second);
        }
        int ans=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<int> remain;
            while(cycle and !pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq>1){
                    remain.push_back(freq-1);
                }
                --cycle;
                ++ans;
            }
            for(auto count: remain){
                pq.push(count);
            }
            if(pq.empty()){
                break;
            }
            ans+=cycle;
        }
        return ans;
    }
};