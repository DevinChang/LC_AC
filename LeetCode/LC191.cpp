



int hammingWeight(uint32_t n) {
    int res = 0;
    for(int i = 0; i < 32; i++){
        res += (n >> i & 1);
    }
    return res;
}