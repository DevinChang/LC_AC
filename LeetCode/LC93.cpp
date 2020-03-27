//
// Created by devinchang on 2019/12/10.
//
#include <bits/stdc++.h>
using namespace std;


vector<string> restoreIpAddress(string s){
    if(s.length() < 4 || s.length() > 12)
        return {};
    vector<string> ret;
    for(int a = 1; a < 4; a++){
        for(int b = 1; b < 4; b++){
            for(int c = 1; c < 4; c++){
                for(int d = 1; d < 4; d++){
                    if(a + b + c + d == s.length()){
                        int A = stoi(s.substr(0, a));
                        int B = stoi(s.substr(a, b));
                        int C = stoi(s.substr(a+b, c));
                        int D = stoi(s.substr(a+b+c, d));
                        if(A <= 255 && B <= 255 && C <=255 && D <=255){
                            string tmp = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                            if(tmp.length() == s.length() + 3)
                                ret.push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    return ret;
}


int main(){
    string s1 = "25525511135";
    auto ret = restoreIpAddress(s1);
    for(auto r : ret){
        std::cout << r << endl;
    }
    return 0;
}

