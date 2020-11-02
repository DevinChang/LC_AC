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
   string path;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        encode(root);
        return path;
    }

    void encode(TreeNode* root) {
        if (!root) path += "#,";
        else {
            path += to_string(root->val) + ',';
            encode(root->left);
            encode(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return decode(data, u);
    }

    TreeNode* decode(string& data, int& u) {
        if (data[u] == '#') {
            u += 2;
            return NULL;
        }
        int k = u;
        while (data[u] != ',') u ++ ;
        auto root = new TreeNode(stoi(data.substr(k, u - k)));
        u ++ ;
        root->left = decode(data, u);
        root->right = decode(data, u);
        return root;
    }
};