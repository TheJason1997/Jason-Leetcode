// Time:  O(n)
// Space: O(1)
// double pointer

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;

        // fast is n-step ahead
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // when fast reaches the end, the slow must be the nth to last node
        // in other word, when fast reaches the last node, the slow->next must be the node needs to be removed
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node_to_remove = slow->next;
        slow->next = slow->next->next;  // link the list again
        delete node_to_remove;

        return dummy.next;
    }
};