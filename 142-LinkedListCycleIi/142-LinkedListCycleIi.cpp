// Last updated: 8/23/2025, 2:39:15 PM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool isLoop=false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
            isLoop=true;
            break;
            }   
        }
        if(!isLoop) return nullptr;

        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};