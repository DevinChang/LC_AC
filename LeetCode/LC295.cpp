
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int> down;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(down.empty() || num <= down.top()){
            down.push(num);
            if(down.size() > up.size()+1){
                up.push(down.top());
                down.pop();
            }
        }
        else {
            up.push(num);
            if(up.size() > down.size()){
                down.push(up.top());
                up.pop();
            }
        }
    }
    
    double findMedian() {
        if((up.size() + down.size()) % 2) return down.top();
        else return (down.top() + up.top()) / 2.0;
    }
};