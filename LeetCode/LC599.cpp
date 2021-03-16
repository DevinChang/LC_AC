class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash;
        int sum = INT_MAX;
        vector<string> res;
        for(int i = 0; i < list1.size(); i++) hash[list1[i]] = i;
        for(int i = 0; i < list2.size(); i++) {
            auto &s = list2[i];
            if(hash.count(s)) {
                int k = hash[s] + i;
                if(k < sum) {
                    sum = k;
                    res = {s};
                } else if(k == sum) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};