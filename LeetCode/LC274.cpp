
int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    for(int h = citations.size(); h; h--){
        if(citations[h-1] >= h) return h;
    }
    return 0;
}