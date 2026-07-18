// Last updated: 18/07/2026, 19:57:33
class Solution {
public:
  
    bool isSameAfterReversals(int num) {
        if(num == 0)
        {
            return true;
        }
            
        if(num%10==0)
        {
            return false;
        }
        return true;
    }
};