


int countPrimes(int n){
    vector<int> primes;
    vector<bool> st(n+1);
    for(int i = 2; i < n; i++) {
        if(!st[i]) primes.push_back(i);
        for(int j = 0; i * primes[j] < n; j++) {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
    return primes.size();
}