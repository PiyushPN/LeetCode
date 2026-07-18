// Last updated: 18/07/2026, 20:01:58
class Solution {
public:
    int find(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += ((n%10)*(n%10));
            n/=10;
        }
        return ans;
    }
//     bool isHappy(int n) {
//         int num1 = find(n);
//         int num2 = find(find(n));
//         while(num1 != num2)
//         {
//             num1 = find(num1);
//             num2 = find(find(num2));
//         }
//         if(num1 == 1)
//         {
//             return 1;
//         }
//         return 0;
//     }
    
    bool isHappy(int n){
        unordered_map<int,int> mp;
        while(n!=1 and mp.find(n)==mp.end()){
            mp[n]=1;
            n=find(n);
        }
        return n==1;
    }
    
    
};