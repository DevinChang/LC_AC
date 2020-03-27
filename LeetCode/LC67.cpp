//
// Created by devinchang on 2019/11/21.
//

#include <bits/stdc++.h>
using namespace std;


string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string ret;
    while (i >= 0 && j >= 0) {
        int tmp = a[i--] - '0' + b[j--] - '0' + carry;
        if (tmp >= 2) {
            carry = 1;
            tmp %= 2;
        } else
            carry = 0;
        ret = to_string(tmp) + ret;
    }
    while (i >= 0) {
        int tmp = a[i--]-'0' + carry;
        if (tmp >= 2) {
            tmp %= 2;
            carry = 1;
        } else
            carry = 0;
        ret = to_string(tmp) + ret;
    }
    while (j >= 0) {
        int tmp = b[j--]-'0' + carry;
        if (tmp >= 2) {
            tmp %= 2;
            carry = 1;
        } else
            carry = 0;
        ret = to_string(tmp) + ret;
    }
    if (carry > 0)
        ret = '1' + ret;
    return ret;


}

struct {
    char *a;
    short b;
    double c;
    char d;
    float e;
    char f;
    long g;
    int h;
} rec;


int main(){
    string a = "100", b = "110010";
    //auto ans = addBinary(a, b);



    cout << "struct rec size =  "<< sizeof(rec) << endl;

    return 0;
}

