/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 我希望3的上一层是1
        // 4->3,3->nullptr
        // 2->1,1->nullptr
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newhead = swapPairs(head->next->next);
        ListNode *answerHead = head->next;
        head->next->next = head;
        head->next = newhead;
        return answerHead;
    }
};
// @lc code=end
