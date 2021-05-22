class ExamRoom {
public:
    vector<int> seats;
    int n;
    ExamRoom(int N) {
        n = N;
    }

    int seat() {
        if (seats.empty()) {
            seats.push_back(0);
            return 0;
        }
        int maxDist = max(seats.front() - 0, n - 1 - seats.back());
        for (int i = 1; i < seats.size(); i++) {
            maxDist = max(maxDist, (seats[i] - seats[i - 1]) / 2);
        }
        if (maxDist == seats.front() - 0) {
            seats.insert(seats.begin(), 0);
            return 0;
        }
        for (int i = 1; i < seats.size(); i++) {
            if (maxDist == (seats[i] - seats[i - 1]) / 2) {
                seats.insert(seats.begin() + i, seats[i - 1] + maxDist);
                return seats[i];
            }
        }

        seats.push_back(n - 1);
        return n - 1;
    }

    void leave(int p) {
        for (int i = 0; i < seats.size(); i++)
            if (seats[i] == p) {
                seats.erase(seats.begin() + i);
                break;
            }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */