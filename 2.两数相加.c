/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.86%)
 * Likes:    4658
 * Dislikes: 0
 * Total Accepted:    492.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* r = NULL;
    struct ListNode* temp = NULL;
    int bit = 0;
    while(l1 || l2 || bit)
    {
        if(!r)
        {
            r = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp = r;
        }
        else
        {
            temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp=temp->next;
        }
        temp->val = (l1?l1->val:0)+(l2?l2->val:0)+bit;
        temp->next = NULL;
        bit = temp->val/10;
        temp->val = temp->val%10;
        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;
    }
    return r;
}

// @lc code=end

