#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;



const int N = 110;
int a[N], b[N];





int main(){
    for(int i = 1; i <= 100; i++) a[i] = i;

    int range = 100;

    for(int i = 0; i < 100; i++){
        int r = rand() % range;
        b[i] = a[r];
        a[r] = a[range-1];
        range--;
    }

    for(int i = 0; i < 100; i ++) printf("%d ", b[i]);

    


    return 0;
}