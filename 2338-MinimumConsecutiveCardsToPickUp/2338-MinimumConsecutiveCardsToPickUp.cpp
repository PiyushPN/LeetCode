// Last updated: 18/07/2026, 19:56:51
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
      map<int,int> mp;int mn=100001;
        for(int i=0;i<cards.size();i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {
                mn=min(mn,(i-mp[cards[i]])+1);
            }
            mp[cards[i]]=i;
        }
        return mn==100001?-1:mn;
    }
};