class TopVotedCandidate {
public:
    vector<int> win;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& _times) {
        int n = persons.size();
        win.resize(n);
        times = _times;
        vector<int> sum(n + 1);

        int maxc = 0, maxp;
        for (int i = 0; i < n; i ++ ) {
            int p = persons[i];
            if ( ++ sum[p] >= maxc) {
                maxc = sum[p];
                maxp = p;
            }
            win[i] = maxp;
        }
    }

    int q(int t) {
        int k = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return win[k];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */