class Solution {
public:
    int r, c, k;
    unordered_map<int, int> hash;

    Solution(int n_rows, int n_cols) {
        r = n_rows, c = n_cols;
        k = r * c;
    }

    vector<int> flip() {
        int x = rand() % k;
        int y = x;
        if (hash.count(x)) y = hash[x];
        if (hash.count(k - 1)) {
            hash[x] = hash[k - 1];
            hash.erase(k - 1);
        } else {
            hash[x] = k - 1;
        }
        k -- ;
        return {y / c, y % c};
    }

    void reset() {
        k = r * c;
        hash.clear();
    }
};
