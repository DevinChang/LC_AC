//
// Created by devinchang on 2020/3/21.
//

#include <bits/stdc++.h>

using namespace std;


/* 八数码
 * 这道题求最短距离，可以首先想到用BFS做。这道题的特殊地方是将网格中的数据当做状态，即
 * 将整个网格用字符串存储，并比较字符串
 */

int bfs(string &start){
    queue<string> que;
    unordered_map<string, int> d;
    // 定义终止状态
    string end = "12345678x";
    que.push(start);
    d[start] = 0;

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

    while(!que.empty()){
        auto t = que.front();
        que.pop();

        // 比较是否到达最终状态
        if(t == end) return d[t];

        int dist = d[t];

        // 找到x的下标
        int k = t.find('x');
        int x = k / 3, y = k % 3; // 转换成网格坐标
        // 转移状态
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
               swap(t[a * 3 + b], t[k]);
               if(!d.count(t)){
                   d[t] = dist + 1;
                   que.push(t);
               }
               // 恢复状态
               swap(t[a*3 + b], t[k]);
            }
        }

    }
    return -1;
}



int main(){
    string start;
    for(int i = 0; i < 9; i++){
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}

