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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            return nullptr;
        }
        ListNode* beforeMiddle = head;
        ListNode* tail = head->next->next;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next->next;
            beforeMiddle = beforeMiddle->next;
        }
        beforeMiddle->next = beforeMiddle->next->next;
        return head;
    }
};
