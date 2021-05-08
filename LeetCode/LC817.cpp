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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> S(G.begin(), G.end());
        int res = 0, s = 0;
        for (auto p = head; p; p = p->next) {
            if (S.count(p->val)) s ++ ;
            else {
                if (s) {
                    s = 0;
                    res ++ ;
                }
            }
        }
        if (s) res ++ ;
        return res;
    }
};