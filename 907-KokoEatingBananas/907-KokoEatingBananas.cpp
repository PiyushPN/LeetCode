// Last updated: 18/07/2026, 19:59:20
class Solution {
public:
    bool solve(int speed, vector<int>&piles, int h){
        int total_hours = 0;
        for(double num:piles){
            double hours=num/speed;
            total_hours+=ceil(hours);
        }
        return total_hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1, end=*(max_element(piles.begin(), piles.end()));
        int n = piles.size();
        while(start<end){
            int mid=start+(end-start)/2;
            if(solve(mid, piles, h)){
                end = mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};