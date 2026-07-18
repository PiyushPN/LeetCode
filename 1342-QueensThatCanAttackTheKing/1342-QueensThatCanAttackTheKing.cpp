// Last updated: 18/07/2026, 19:58:49
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queen, vector<int>& king) {
        int n=8;
        vector<vector<int>>ans;
        vector<pair<int,int>> queens;
        for(auto i:queen){
            queens.push_back(make_pair(i.front(),i.back()));
        }
        int x=king[0]-1,y=king[1]-1;
        //left up diagonal
        while(x>=0 and y>=0){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x--;
            y--;
        }        
        
         //right down diagonal
        x=king[0]+1,y=king[1]+1;
        while(x<n and y<n){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x++;
            y++;
        }   
        
        
        //left lower diagonal
        x=king[0]+1,y=king[1]-1;
        while(x<n and y>=0){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x++;
            y--;
        }   
        
        
       //right up diagonal
        x=king[0]-1,y=king[1]+1;
        while(x>=0 and y<n){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x--;
            y++;
        }   
        
        //right
        x=king[0],y=king[1]+1;
        while(y<n){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            y++;
        }   
        //left
        x=king[0],y=king[1]-1;
        while(y>=0){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            y--;
        }
        
        //down
        x=king[0]+1,y=king[1];
        while(x<n){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x++;
        }
        
        //up
        x=king[0]-1,y=king[1];
        while(x>=0){
            pair<int,int> v={x,y};
            if(find(queens.begin(),queens.end(),v)!=queens.end())
            {
                ans.push_back({x,y});
                break;
            }
            x--;
        }
        return ans;
        
    }
};