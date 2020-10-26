
int addDigits(int num) {
    while(num >= 10){
        int t = 0;
        while(num > 0){
            t = t + num % 10;
            num /= 10;
        }
        num = t;
    }
    return num;
}

int addDigits(int num){
    if(num == 0) return num;
    if(num % 9) return num % 9;
    return 9;
}