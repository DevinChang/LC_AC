class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int front, rear, n, sz;
    vector<int> buffer;

    MyCircularDeque(int k) {
        buffer.resize(k);
        n = k;
        sz = 0;
        front = rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front + n - 1) % n;
        buffer[front] = value;
        sz++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        buffer[rear++] = value;
        rear %= n;
        sz++;
        return true;
    }
/** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % n;
        sz--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear = (rear + n - 1) % n;
        sz--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return buffer[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return buffer[(rear + n - 1) % n];
    }

 /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return sz == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return sz == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
