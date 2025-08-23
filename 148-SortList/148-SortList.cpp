// Last updated: 8/23/2025, 2:39:09 PM
class Solution {
public:
    ListNode* mergeSort(ListNode* slowHead, ListNode* fastHead) {
        ListNode* dummy = new ListNode(); // dummy node to build final merged list
        ListNode* final = dummy;

        while (slowHead != nullptr && fastHead != nullptr) {
            if (slowHead->val < fastHead->val) {
                final->next = slowHead;
                slowHead = slowHead->next;
            } else {
                final->next = fastHead;
                fastHead = fastHead->next;
            }
            final = final->next;
        }

        while (slowHead != nullptr) {
            final->next = slowHead;
            slowHead = slowHead->next;
            final = final->next;
        }

        while (fastHead != nullptr) {
            final->next = fastHead;
            fastHead = fastHead->next;
            final = final->next;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* slowHead = sortList(head);
        ListNode* fastHead = sortList(slow);

        return mergeSort(slowHead, fastHead);
    }
};
