//
// Created by devinchang on 2020/2/20.
//
#include "util.h"


int smallestFactorization(int a){
    if(a < 9)
        return a;
    long long res = 0;
    long long mul = 1;
    for(int i = 9; i >= 2; i--){
        while(a % i == 0){
            res = mul * i + res;
            if(res > INT_MAX)
                return 0;
            mul *= 10;
            a /= i;
        }
    }
    if(a != 1)
        return 0;
    return res;
}






int main(){
    string line;
    while(getline(cin, line)){
        auto a = stringToInteger(line);
        int out = smallestFactorization(a);
        cout << out << endl;
    }


    return 0;
}

