class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ret;
        for(auto n : nums1) s.insert(n);
        for(auto n : nums2){
            if(s.count(n)){
                ret.push_back(n);
                s.erase(n);
            }
        }
        return ret;
    }
};