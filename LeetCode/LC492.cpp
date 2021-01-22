class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); ; i--) {
            if(area % i == 0) {
                return {area / i, i};
            }
        }
        return {};
    }
};