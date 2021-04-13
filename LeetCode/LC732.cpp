class MyCalendarThree {
public:
    map<int,int> S;
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        S[start]++, S[end]--;
        int sum = 0, res = 0;
        for(auto [k,v] : S) {
            sum += v;
            res = max(res, sum);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */