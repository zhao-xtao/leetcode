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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = nullptr, *p = nullptr;
        int t = 0;
        while (l1 || l2) {
            if (l1) t += l1->val;
            if (l2) t += l2->val;

            if (l3 == nullptr) {
                l3 = p = new ListNode(t % 10);
            } else {
                p->next = new ListNode(t % 10);
                p = p->next;
            }
            t /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (t) {
            ListNode *new_node = new ListNode(t);
            p->next = new_node;
        }
        return l3;
    }
};
