class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int,int> last;
        int n = S.size();
        for(int i = 0; i < n; i++) last[S[i]] = i;
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++) {
            end = max(end, last[S[i]]);
            if(i == end) {
                res.push_back(end - start + 1);
                start = end = i+1;
            }
        }
        return res;
    }
};