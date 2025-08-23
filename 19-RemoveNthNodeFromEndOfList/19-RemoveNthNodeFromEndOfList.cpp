// Last updated: 8/23/2025, 2:40:33 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        if(n == count) {
            return head->next;
        }
        cout<<count;
        int nodeToRemove=count-n;
        count=0;
        temp=head;
        while(temp!=nullptr){
            count++;
            if(nodeToRemove==count){
                ListNode* x=temp->next;
                temp->next=x->next;
                x->next=nullptr;
                delete x;
            }
            temp=temp->next;
        }
        return head;
    }
};