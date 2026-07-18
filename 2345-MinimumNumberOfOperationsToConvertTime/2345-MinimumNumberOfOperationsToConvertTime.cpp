// Last updated: 18/07/2026, 19:56:47
class Solution {
public:
    int convertTime(string current, string correct) {
        string h1 = "";
        h1+=current[0];
        h1+=current[1];
        string m1 = "";
        m1+=current[3];
        m1+=current[4];
        string h2 = "";
        h2+=correct[0];
        h2+=correct[1];
        string m2 = "";
        m2+=correct[3];
        m2+=correct[4];
        int time1=stoi(h1)*60+stoi(m1);
        int time2=stoi(h2)*60+stoi(m2);
        int ans=0;
        
        while(time2>time1){
            
            if((time2-time1)>=60){
                time1=time1+60;
                ans++;
            }
            else if((time2-time1)>=15){
                time1=time1+15;
                ans++;
            }
            else if((time2-time1)>=5){
                time1=time1+5;
                ans++;
            }
            else {
                ans+=(time2-time1);
                time1=time1+(time2-time1);
            }
        }
        return ans;
            
    }
};