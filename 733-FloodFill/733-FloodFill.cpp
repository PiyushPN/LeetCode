// Last updated: 18/07/2026, 19:59:31
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int m = image.size();
        int n = image[0].size();
        q.push({sr, sc});
        int scolor = image[sr][sc];
        image[sr][sc] = color;
        if(scolor == color)
        {
            return image;
        }
        while(!q.empty())
        {
            int size = q.size();
            for(int k = 0; k < size; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i+1<m and image[i+1][j] == scolor)
                {
                    q.push({i+1, j});
                    image[i+1][j] = color;
                }
                if(j+1<n and image[i][j+1] == scolor)
                {
                    q.push({i, j+1});
                    image[i][j+1] = color;
                }
                if(i-1>=0 and image[i-1][j] == scolor)
                {
                    q.push({i-1, j});
                    image[i-1][j] = color;
                }
                if(j-1>=0 and image[i][j-1] == scolor)
                {
                    q.push({i, j-1});
                    image[i][j-1] = color;
                }
            }
        }
        return image;
        
    }
};