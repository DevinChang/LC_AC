
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + 0ll + r) / 2;
        if(isBadVersion(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}