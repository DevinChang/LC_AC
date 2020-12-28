/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    void dfs_s(TreeNode* root, string& res) {
        if(!root) return;
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        vector<int> data;
        stringstream ssin(str); 
        int x, u = 0;
        while(ssin >> x) data.push_back(x);
        return dfs_d(data, u, INT_MIN, INT_MAX);
    }

    TreeNode *dfs_d(vector<int>& data, int& u, int minv, int maxv) {
        if(u == data.size() || data[u] < minv || data[u] > maxv) return nullptr;
        auto root = new TreeNode(data[u++]);
        root->left = dfs_d(data, u, minv, root->val);
        root->right = dfs_d(data, u, root->val+1, maxv);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;