class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int maxmass = 1e5;
        for(int i : asteroids){
            if(i<=mass){
                mass = min(mass+i,maxmass);
            }else{
                return false;
            }
        }
        return true;
    }
};