// Time:  O(n)
// Space: O(1)

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = &dummy;

        while (curr->next && curr->next->next) {
            auto one = curr->next;
            auto two = one->next;
            auto three = two->next;

            // relink
            curr->next = two;
            two->next = one;
            one->next = three;

            curr = one; // update
        }

        return dummy.next;
    }
};



// Time:  O(n)
// Space: O(n)
// recursive

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto nextNode = head->next;
        head->next = swapPairs(nextNode->next);
        nextNode->next = head;

        return nextNode;
    }
};