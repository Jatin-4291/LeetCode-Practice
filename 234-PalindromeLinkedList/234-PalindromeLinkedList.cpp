// Last updated: 8/23/2025, 2:38:37 PM
class Solution {
public:
    void solve(ListNode*& l1, ListNode* l2, bool& ans) {
        if (l2 == nullptr) {
            return;
        }
        solve(l1, l2->next, ans);
        if (l1->val != l2->val) {
            ans = false;
        }
        l1 = l1->next;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        bool ans = true;
        solve(temp, head, ans);
        return ans;
    }
};
