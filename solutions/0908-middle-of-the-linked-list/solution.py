# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import math
class Solution(object):
    def middleNode(self, head):
        if(head.next==None):
            return head
        h = head
        nodes_count =1
        while(h.next!=None):
            h = h.next
            nodes_count +=1
        

            d = (nodes_count//2)+1
            
        for i in range(1,d):
            head = head.next
        return head

            
            
            
            
        
            
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
