// Problem: 1290. Convert Binary Number in a Linked List to Integer (Easy)
// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function getDecimalValue(head: ListNode | null): number {
    let val = 0;
    
    while (head != null) {
        val *= 2;
        val += head.val;
        head = head.next;
    }

    return val;     
};