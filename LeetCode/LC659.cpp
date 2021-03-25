class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> origin, link;
        for(auto x : nums) origin[x]++;
        for(auto x : nums) { 
            if(!origin[x]) continue;
            if(link[x-1]) {
                link[x-1]--;
                link[x]++;
                origin[x]--;
            } else if(origin[x+1] && origin[x+2]){
                link[x+2]++;
                origin[x]--;
                origin[x+1]--;
                origin[x+2]--;
            }
            else return false;
        }
        return true;
    }
};