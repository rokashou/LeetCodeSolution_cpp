#include "../leetcode.h"
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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode* newHead = new ListNode();
        if (head->val >= 5)
        {
            newHead->val = 1;
            newHead->next = head;
        }
        else
            newHead = head;

        ListNode* node = head;
        while(node != nullptr){
            node->val = node->val * 2;
            if (node->next != nullptr && node->next->val >= 5)
                node->val += 1;
            if (node->val > 9)
                node->val -= 10;

            node = node->next;
        }
        return newHead;
    }
};