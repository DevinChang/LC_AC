

class WordDictionary {
public:
    struct Node{
        bool is_end;
        Node *son[26];
        Node(){
            is_end = false;
            for(int i = 0; i < 26; i++) son[i] = nullptr;
        }
    }*root; 

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = root;
        for(auto c : word){
            int u = c - 'a';
            if(!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node *p, string &word, int i){
        if(i == word.size()) return p->is_end;
        if(word[i] != '.'){
            int u = word[i] - 'a';
            if(!p->son[u]) return false;
            return dfs(p->son[u], word, i+1);
        }else{
            for(int j = 0; j < 26; j++){
                if(p->son[j] && dfs(p->son[j], word, i+1))
                    return true;
            }
        }
        return false;
    }
};