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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        auto root = &dummy, curr = head;
        int len = 0;

        while (curr) {
            auto next_curr = curr->next;    // need to save the next ptr to avoid changing
            len = (len + 1) % k;    // take surplus to decide whether reverse

            if (len == 0) {
                auto next_root = root->next;    // need to save the next ptr to avoid changing
                reverse(root, curr->next);
                root = next_root;
            }
            curr = next_curr;
        }

        return dummy.next;
    }

private:
    void reverse(ListNode* begin, ListNode* end) {
        auto first = begin->next;
        auto curr = first->next;

        while (curr != end) {
            first->next = curr->next;
            curr->next = begin->next;   // notice the next ptr of curr is the ori begin->next
            begin->next = curr;
            curr = first->next;
        }
    }
};



// Time:  O(n*k)
// Space: O(1)

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        auto root = &dummy, end = &dummy;

        while (end->next != nullptr) {
            // decide the len to reverse
            for (int i = 0; i < k && end != nullptr; ++i) {
                end = end->next;
            }

            // attention
            if (end == nullptr) {
                break;
            }

            auto begin = root->next;
            auto next_begin = end->next;
            end->next = nullptr;
            
            root->next = reverse(begin);
            
            begin->next = next_begin;
            root = begin;
            end = root;
        }

        return dummy.next;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        auto curr = head;

        while (curr != nullptr) {
            auto next_curr = curr->next;
            curr->next = prev;   // notice the next ptr of curr is the ori begin->next
            prev = curr;
            curr = next_curr;
        }

        return prev;
    }
};