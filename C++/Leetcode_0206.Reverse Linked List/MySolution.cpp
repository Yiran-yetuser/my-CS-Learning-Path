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
    ListNode* reverseList(ListNode* head) {
        
        // 递归做法
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
        // // 迭代做法
        // if(head == nullptr) {
        //     return nullptr;
        // }
        // ListNode* pre = nullptr;
        // ListNode* nxt = head->next;
        // while (nxt != nullptr) {
        //     head->next = pre;
        //     pre = head;
        //     head = nxt;
        //     nxt = nxt->next;
        // }
        // head->next = pre;
        // return head;
    }
};
