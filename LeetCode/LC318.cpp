class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> state;
        for(auto w : words){
            int s = 0;
            for(auto c : w){
                s |= 1 << (c - 'a');
            }
            state.push_back(s);
        }
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = i + 1; j < n; j ++ )
                if ((state[i] & state[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
        return res;
    }
};