class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        for(int i = 0, j = people.size()-1; i <= j; j--) {
            if(people[i] + people[j] <= limit) i++;
            res++;
        }
        return res;
    }
};