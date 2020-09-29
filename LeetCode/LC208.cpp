class Trie {
    struct Node {
        Node *son[26];
        bool is_end;
        Node(){
            for(int i = 0; i < 26; i++) son[i] = nullptr;
            is_end = false;
        }
    } *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for(auto c : word){
            int u = c - 'a';
            if(!p->son[u]) {
                p->son[u] = new Node();
            }
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for(auto c : word){
            int u = c - 'a';
            if(!p->son[u]) return false;
            p = p->son[u];
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for(auto c : prefix) {
            int u = c - 'a';
            if(!p->son[u]) return false;
            p = p->son[u];
        }
        return true;
    }
};