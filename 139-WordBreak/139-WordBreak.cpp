// Last updated: 18/07/2026, 20:02:48
class Solution {
public:
//     unordered_map<string, bool> dp;
//     bool solve(string &s, unordered_map<string, bool> &mp)
//     {
//         if(s.length()==0)
//         {
//             return true;
//         }
//         if(dp.find(s) != dp.end())
//         {
//             return dp[s];
//         }
//         for(int i = 0; i < s.length(); i++)
//         {
//             string s1 = s.substr(0, i+1);
//             string s2 = s.substr(i+1);
//             if(mp.find(s1) != mp.end())
//             {
//                 if(solve(s2, mp))
//                 {
//                     return dp[s] = 1;
//                 }
//             }
//         }
//         return dp[s] = 0;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         unordered_map<string, bool> mp;
//         for(auto &it: wordDict)
//         {
//             mp[it] = true;
//         }
//         return solve(s, mp);
        
//     }
    int dp[301][301];
    bool solve(int i,int prev,int n,string &s,unordered_set<string>& st){
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        string abhi=s.substr(prev,i-prev+1);
        if(st.find(abhi)!=st.end()){
            if(i==n-1){
                return dp[i][prev]=true;
            }
            if(solve(i+1,prev,n,s,st) or solve(i+1,i+1,n,s,st))
                return dp[i][prev]=true;
        }
        else{
            if(i==n-1)
                return dp[i][prev]=false;
            
            if(solve(i+1,prev,n,s,st))
                return dp[i][prev]=true;
        }
        return dp[i][prev]=false;
        
    }
    bool wordBreak(string s,vector<string> & word){
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st;
        for(auto &i:word)
            st.insert(i);
        return solve(0,0,n,s,st);
    }
    
};