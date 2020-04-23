#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;








int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, id;
        scanf("%d%d", &id, &n);
        // 输出id和有中位数的个数
        printf("%d %d\n", id, (n+1)/2);

        int cnt = 0;

        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            if(down.empty() || x <= down.top()) down.push(x); // 比中位数小的放入大根堆, 否则放入小根堆
            else up.push(x);
            // 因为中位数是存入到大根堆中，所以要保证大根堆的数目比小根堆多1个，若是超出这种平衡，则调整大根小根堆
            if(down.size() > up.size() + 1) up.push(down.top()), down.pop();
            if(up.size() > down.size()) down.push(up.top()), up.pop();

            // 输出中位数
            if(i % 2 == 0){
                printf("%d ", down.top());
                if(++cnt % 10 == 0) puts("");
            }
        }
        if(cnt % 10) puts("");
    }


    return 0;
}