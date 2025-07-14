# Problem: 1290. Convert Binary Number in a Linked List to Integer (Easy)
# Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        val = 0
        
        while head is not None:
            val *= 2
            val += head.val
            head = head.next

        return val