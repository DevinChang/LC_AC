#include <iostream>
#include <unordered_map>
using namespace std;



int maxPoints(vector<vector<int>>& points) {
int n = points.size();
    if (n < 3) return n;
    int ret = 0;
    for(int i = 0; i < n; i++)  {
        int vertical = 1, duplicates = 0;
        unordered_map<long double, int> hash;
        for (int j = i + 1; j < n; j++)  {
            if(points[i][0] == points[j][0]) {
                vertical++;
                if(points[i][1] == points[j][1]) duplicates++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if(points[i][0] != points[j][0]){
                long double k = (long double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                if (hash[k] == 0) hash[k] = 2;
                else hash[k]++;
                ret = max(ret, hash[k]+duplicates);
            }
        }
        ret = max(ret, vertical);
    }
    return ret;
    }