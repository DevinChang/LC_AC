class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto aster : asteroids) {
            if(aster > 0) res.push_back(aster);
            else {
                while(res.size() && res.back() > 0 && res.back() < -aster) res.pop_back();
                if (res.size() && res.back() == -aster) res.pop_back();
                else if(res.empty() || res.back() < 0) res.push_back(aster);
            }
        }
        return res;
    }
};