
// lowbit运算
bool isPowerOfTwo(int n){
    return (n > 0) ? ((n & -n) == n) : false;
}