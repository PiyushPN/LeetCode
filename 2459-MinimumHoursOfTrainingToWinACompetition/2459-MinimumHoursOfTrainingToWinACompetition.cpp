// Last updated: 18/07/2026, 19:56:23
class Solution {
public:
    int minNumberOfHours(int iE, int iExp, vector<int>& energy, vector<int>& experience) {
        int eH = 0, expH = 0;
        int n = energy.size();
        for(int i = 0; i < n; i++)
        {
            if(energy[i] >= iE)
            {
                int temp = energy[i]-iE+1;
                eH += temp;
                iE = iE+temp;
            }
            if(experience[i] >= iExp)
            {
                int temp = experience[i]-iExp+1;
                expH += temp;
                iExp = temp+iExp;
                
            }
            iE = iE-energy[i];
            iExp += experience[i];
        }
        return eH+expH;
    }
};