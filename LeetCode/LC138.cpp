#include <iostream>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val, Node *_next, Node *_random) : var(_val), next(_next), random(_random) {}
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        unordered_map<Node*, Node*> hash;
        Node *root = new Node(head->val, NULL, NULL);
        hash[head] = root;
        while(head->next){
            if(hash.count(head->next) == 0)
                hash[head->next] = new Node(head->next->val, NULL, NULL);
            hash[head]->next = hash[head->next];
            if(head->random && hash.count(head->random) == 0)
                hash[head->random] = new Node(head->random->val, NULL, NULL);
            hash[head]->random = hash[head->random];
            head = head->next;
        }
        // 处理尾结点
        if (head->random && hash.count(head->random) == 0)
            hash[head->random] = new Node(head->random->val, NULL, NULL);
        hash[head]->random = hash[head->random];
        return root;
    }
}
