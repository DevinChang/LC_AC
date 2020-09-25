


int rangeBitwiseAnd(int m, int n) {
    int res = 0;
    for (int i = 30; i >= 0; i -- ) {
        if ((m >> i & 1) != (n >> i & 1)) break;
        if (m >> i & 1) res += 1 << i;
    }
    return res;
}