// Last updated: 8/30/2025, 1:23:48 PM
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
    void solve(ListNode* head, ListNode*& ans, int& carry) {
        if (head == nullptr) {
            return;
        }
        solve(head->next, ans, carry);
        ans = new ListNode((head->val * 2) % 10 + carry, ans);
        carry = (head->val * 2) / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* ans = nullptr;
        int carry = 0;
        solve(head, ans, carry);
        if (carry) {
            ans = new ListNode(carry, ans);
        }
        return ans;
    }
};
