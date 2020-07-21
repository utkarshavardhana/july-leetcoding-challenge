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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        while(node) {
            while(node->next and node->next->val == val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return head ? (
            (head->val == val) ? head->next : head
        ) : NULL;
    }
};
