/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode st;
        st.next = head;
        int pr = 0;
        unordered_map<int, ListNode *> nod;
        for (ListNode *node = &st; node; node = node->next) {
            pr += node->val;
            nod[pr] = node;
        }
        pr = 0;
        for (ListNode *node = &st; node; node = node->next) {
            pr += node->val;
            node->next = nod[pr]->next;
        }
        return st.next;
    }
};
