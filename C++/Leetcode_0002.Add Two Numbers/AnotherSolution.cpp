class Solution {
public:
    // l1 和 l2 为当前遍历的节点，carry 为进位
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) { // 递归边界
            return carry ? new ListNode(carry) : nullptr; // 如果进位了，就额外创建一个节点
        }
        if (l1 == nullptr) { // 如果 l1 是空的，那么此时 l2 一定不是空节点
            swap(l1, l2); // 交换 l1 与 l2，保证 l1 非空，从而简化代码
        }
        int sum = carry + l1->val + (l2 ? l2->val : 0); // 节点值和进位加在一起
        l1->val = sum % 10; // 每个节点保存一个数位（直接修改原链表）
        l1->next = addTwoNumbers(l1->next, (l2 ? l2->next : nullptr), sum / 10); // 进位
        return l1;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/add-two-numbers/solutions/2327008/dong-hua-jian-ji-xie-fa-cong-di-gui-dao-oe0di/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
