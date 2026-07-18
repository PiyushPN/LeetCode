// Last updated: 18/07/2026, 19:57:27
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long mass1 = mass;
        for(int i = 0; i < n; i++)
        {
            if(mass1>=asteroids[i])
            {
                mass1+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};