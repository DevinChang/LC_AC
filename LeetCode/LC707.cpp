class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int _val): val(_val), next(NULL) {}
    }*head;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0) return -1;
        auto p = head;
        for (int i = 0; i < index && p; i ++ ) p = p->next;
        if (!p) return -1;
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto cur = new Node(val);
        cur->next = head;
        head = cur;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head) head = new Node(val);
        else {
            auto p = head;
            while (p->next) p = p->next;
            p->next = new Node(val);
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) addAtHead(val);
        else {
            int len = 0;
            for (auto p = head; p; p = p->next) len ++ ;
            if (index == len) addAtTail(val);
            else {
                auto p = head;
                for (int i = 0; i < index - 1; i ++ ) p = p->next;
                auto cur = new Node(val);
                cur->next = p->next;
                p->next = cur;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int len = 0;
        for (auto p = head; p; p = p->next) len ++ ;
        if (index >= 0 && index < len) {
            if (!index) head = head->next;
            else {
                auto p = head;
                for (int i = 0; i < index - 1; i ++ ) p = p->next;
                p->next = p->next->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */