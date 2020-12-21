/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto res = dfs(head);
        return res[0];
    }

    vector<Node*> dfs(Node* head) {
        if(!head) return {NULL, NULL};
        auto cur = head, tail = head;
        while(cur) {
            tail = cur;
            if(cur->child) {
                auto t = dfs(cur->child);
                cur->child = NULL;
                t[1]->next = cur->next;
                if(cur->next) cur->next->prev = t[1];
                cur->next = t[0];
                t[0]->prev = cur;
                cur = t[1]->next;
                tail = t[1];
            }
            else {
                cur = cur->next;
            }
        }
        return {head, tail};
    }
};