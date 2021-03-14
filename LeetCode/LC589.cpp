/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<pair<Node*,int>> st;
        st.push(make_pair(root,0));
        while(!st.empty()) {
            auto cur = st.top();
            st.pop();
            if(cur.second == 0) ans.push_back(cur.first->val);
            if(cur.second < cur.first->children.size()) {
                st.push(make_pair(cur.first, cur.second+1));
                st.push(make_pair(cur.first->children[cur.second], 0));
            }
        }
        return ans;
    }
};