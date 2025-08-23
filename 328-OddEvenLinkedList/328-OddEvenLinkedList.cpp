// Last updated: 8/23/2025, 2:38:20 PM
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        while(even!=nullptr && even->next!=nullptr){
            odd->next=even->next;
            even->next=even->next->next;
            even=even->next;
            odd=odd->next;
        }
        odd->next=evenHead;
        return head;
    }
};
