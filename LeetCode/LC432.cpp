class AllOne {
public:
    struct Node {
        Node *left, *right;
        int val;
        unordered_set<string> S;

        Node (int _val) {
            val = _val;
            left = right = NULL;
        }
    }*left, *right;
    unordered_map<string, Node*> hash;

    /** Initialize your data structure here. */
    AllOne() {
        left = new Node(INT_MIN), right = new Node(INT_MAX);
        left->right = right, right->left = left;
    }

    Node* add_to_right(Node* node, string key, int val) {
        if (node->right->val == val) node->right->S.insert(key);
        else {
            auto t = new Node(val);
            t->S.insert(key);
            t->right = node->right, node->right->left = t;
            node->right = t, t->left = node;
        }
        return node->right;
    }

    Node* add_to_left(Node* node, string key, int val) {
        if (node->left->val == val) node->left->S.insert(key);
        else {
            auto t = new Node(val);
            t->S.insert(key);
            t->left = node->left, node->left->right = t;
            node->left = t, t->right = node;
        }
        return node->left;
    }

    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (hash.count(key) == 0) hash[key] = add_to_right(left, key, 1);
        else {
            auto t = hash[key];
            t->S.erase(key);
            hash[key] = add_to_right(t, key, t->val + 1);
            if (t->S.empty()) remove(t);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (hash.count(key) == 0) return;
        auto t = hash[key];
        t->S.erase(key);
        if (t->val > 1) {
            hash[key] = add_to_left(t, key, t->val - 1);
        } else {
            hash.erase(key);
        }
        if (t->S.empty()) remove(t);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (right->left != left) return *right->left->S.begin();
        return "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (left->right != right) return *left->right->S.begin();
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

