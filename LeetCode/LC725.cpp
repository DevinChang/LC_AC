/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        for (auto p = root; p; p = p->next) n ++ ;

        vector<ListNode*> res;
        auto p = root;
        for (int i = 0; i < k; i ++ ) {
            int len = n / k;
            if (i + 1 <= n % k) len ++ ;
            res.push_back(p);
            for (int j = 0; j < len - 1; j ++ ) p = p->next;
            if (p) {
                auto q = p->next;
                p->next = NULL;
                p = q;
            }
        }
        return res;
    }
};