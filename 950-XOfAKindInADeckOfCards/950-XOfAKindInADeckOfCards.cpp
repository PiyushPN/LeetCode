// Last updated: 18/07/2026, 19:59:14
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(int i: deck){
            mp[i]++;
        }
        int gcd = 0;
        for(auto i: mp){
            gcd = __gcd(i.second, gcd);
        }
        return gcd > 1;
    }
};