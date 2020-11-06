
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        typedef pair<int, int> PII;
        int k = primes.size();
        vector<int> res(n), idx(k, 0);
        priority_queue<PII, vector<PII>, greater<PII>> heap;

        res[0] = 1;
        for(int i = 0; i < k; i++) heap.push(make_pair(primes[i], i));

        for(int i = 1; i < n; i++){
            int mi = heap.top().first;
            res[i] = mi;
            while(heap.top().first == mi){
                int p = heap.top().second;
                heap.pop();
                idx[p]++;
                if(1ll * res[idx[p]] * primes[p] <= INT_MAX) heap.push(make_pair(res[idx[p]] * primes[p], p));
            }
        }
        return res[n-1];
    }
};