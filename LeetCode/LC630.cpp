class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b) {
            return a[1] < b[1];
        });
        priority_queue<int> heap;
        int tot = 0;
        for(auto &c : courses) {
            tot += c[0];
            heap.push(c[0]);
            if(tot > c[1]) {
                tot -= heap.top();
                heap.pop();
            }
        }
        return heap.size();
    }
};