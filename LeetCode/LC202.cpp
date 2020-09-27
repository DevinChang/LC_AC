


bool isHappy(int n) {
    int m = n;
    unordered_set<int> hash;
    while(true){
        int sum = 0;
        while(m != 0) {
            sum += (m % 10) * (m % 10);
            m /= 10;
        }
        if(sum ==1 ) return true;
        else if (hash.find(sum) != hash.end()) return false;
        else hash.insert(sum);
        m = sum;
    }
    return false;
}

int get(int x){
    int sum = 0;
    while(x){
        sum += (x % 10) * (x % 10);
        x /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = get(n);
    while(slow != fast) {
        slow = get(slow);
        fast = get(get(fast));
    }
    return fast == 1;
}