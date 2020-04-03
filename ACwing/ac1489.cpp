#include <iostream>
#include <algorithm>


using namespace std;


const int N = 1010;
int A[N], B[N];
int n;



int main(){

    while(cin >> n, n){
        for(int i = 0;i < n; i++) scanf("%d", &A[i]);
        for(int i = 0;i < n; i++) scanf("%d", &B[i]);
        
        // 将A，B按从大到小顺序排序
        sort(A, A+n, greater<int>());
        sort(B, B+n, greater<int>());

        int ans = 0;

        int f1 = 0, f2 = 0, s1 = n-1, s2 = n-1;
        while(f1 <= s1){
            // A最后一匹马比B最后一匹马快，这种情况最佳
            if(A[s1] > B[s2]){
                ans++;
                s1--, s2--;
            }
            else if(A[s1] < B[s2]){ // A最后一匹马比B最后一匹马慢，则让A的最后一匹马当炮灰与B最好的马比
                ans += A[s1] < B[f1] ? -1 : 0;
                s1--, f2++;
            }
            else{ // A最后一匹马与B最后一匹马相等时
                if(A[f1] > B[f2]){
                    ans++;
                    f1++, f2++;
                }
                else{ // 不论何种情况，都是让A最慢的马与最快的马比最优
                    ans += A[s1] < B[f2] ? -1 : 0;
                    s1--, f2++;
                }
            }
        }
        printf("%d\n", ans * 200);
    }


    return 0;
}