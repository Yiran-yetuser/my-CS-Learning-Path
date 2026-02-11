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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 利用stack
        stack<int> s1;
        stack<int> s2;
        int sum = 0;
        int carry = 0;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = new ListNode(0);
        ListNode* cur = nullptr;

        while (!s1.empty() || !s2.empty() || carry != 0) {
            sum = carry + (s1.empty() ? 0 : s1.top()) +
                  (s2.empty() ? 0 : s2.top());
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
            carry = sum / 10;
            head = new ListNode(sum % 10);
            head->next = cur;
            cur = head;
        }
        return head;
    }
};
