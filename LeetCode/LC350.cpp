class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s;
        vector<int> res;
        for(auto n : nums1) s.insert(n);
        for(auto n : nums2){
            if(s.count(n)){
                res.push_back(n);
                s.erase(s.find(n));
            }
        }
        return res;
    }
};