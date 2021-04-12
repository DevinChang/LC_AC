class MyCalendar {
public:
    map<int,int> hash;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if(hash.size() == 0) {
            hash[start] = end;
            return true;
        }
        auto it = hash.lower_bound(start);
        bool flag = false;
        if(it == hash.begin() && end <= it->first) flag = true;
        else if (it == hash.end() && (--it)->second <= start) flag = true;
        else {
            auto pre = it;
            pre--;
            if(pre->second <= start && end <= it->first) flag = true;
        }
        if(flag) {
            hash[start] =end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */