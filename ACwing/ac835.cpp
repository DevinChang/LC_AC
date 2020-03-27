#include <iostream>
using namespace std;

/* Trie树 */

const int N = 10010;


int son[N][26]; // 存储树的节点
int cnt[N]; // 用来标识每个节点是否是插入的单词
int idx;
int n;
char str[N];


void insert(char str[]){
    // 父节点，从父节点开始遍历
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    // 记录该单词
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main(){
    scanf("%d", &n);
    while(n--){
        char op[2];
        scanf("%s%s", op, str);
        if(*op == 'I'){
            insert(str);
        }
        if(*op == 'Q'){
            int ret = query(str);
            printf("%d\n", ret);
        }

    }

    return 0;
}