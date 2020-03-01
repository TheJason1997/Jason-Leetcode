// Time:  O(n * logk), n is the length of the result list.
// Space: O(1)
// based on #21 solution and double pointer

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // attention
        if (lists.empty()) {
            return nullptr;
        }

        int left = 0, right = lists.size() - 1;
        while (right > 0) {    // need to notice the loop condition
            if (left >= right) {
                // use lists[left] to merge, so the condition also needs to be noticed
                left = 0;
            }
            else {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                ++left;
                --right;
            }
        }

        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;  // link the rest of longer one

        return dummy.next;
    }
};



// Time:  O(n * logk)
// Space: O(logk)
// divide and conquer

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsDivide(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeKListsDivide(const vector<ListNode*>& lists, int begin, int end) {
        // attention
        if (begin > end) {
            return nullptr;
        }
        if (begin == end) {
            return lists[begin];
        }

        return mergeTwoLists(mergeKListsDivide(lists, begin, (begin + end) / 2),
                             mergeKListsDivide(lists, (begin + end) / 2 + 1, end));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;  // link the rest of longer one

        return dummy.next;
    }
};



// Time:  O(n * logk)
// Space: O(k)
// heap

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy{0};
        auto curr = &dummy;

        // priority_queue<Type, container, functional>
        priority_queue<ListNode*, vector<ListNode*>, less> min_heap;
        
        // use min heap to keep the smallest node of each list(first node as the lists are all sorted)
        for (const auto& n : lists) {
            if (n) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // get min of k lists
            auto *node = min_heap.top();
            min_heap.pop();
            curr->next = node;
            curr = curr->next;

            if (node->next) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }

private:
    // reload the operator: "<" - max heap, ">" - min heap
    struct less {   // the top element is min
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
};