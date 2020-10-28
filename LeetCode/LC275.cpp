
int hIndex(vector<int>& c) {
    int n = c.size();
    for(int h = 0; h < n; h++){
        if(n - h <= c[h]){
            return n - h;
        }
    }
    return 0;
}


int hIndex(vector<int> &c) {
    int n = c.size();
    int l = 0, r = n;
    while(l < r) {
        int mid = l + r +1 >> 1;
        if(c[n-mid] >= mid) l = mid;
        else r = mid - 1;
    }
    return r;
}