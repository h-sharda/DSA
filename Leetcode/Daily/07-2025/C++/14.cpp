// Problem: 1290. Convert Binary Number in a Linked List to Integer (Easy)
// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        int val = 0;
        
        while (head != NULL) {
            val *= 2;
            val += head->val;
            head = head->next;
        }

        return val;
    }
};