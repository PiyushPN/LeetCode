// Last updated: 18/07/2026, 19:58:46
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>> ans;
        map<int, int> mp1, mp2;
        int n = m.size();
        for(int i = 0; i < n; i++){
            mp1[m[i][0]]++;
            mp2[m[i][1]]++;
        }
        vector<int> winners, losers;
        for(auto i=mp1.begin(); i != mp1.end(); i++){
            if(mp2.find(i->first) == mp2.end()){
                winners.push_back(i->first);
            }
        }
        for(auto i=mp2.begin(); i != mp2.end(); i++){
            if(i->second == 1){
                losers.push_back(i->first);
            }
        }
        ans.push_back(winners);
        ans.push_back(losers);
        return ans;
    }
};