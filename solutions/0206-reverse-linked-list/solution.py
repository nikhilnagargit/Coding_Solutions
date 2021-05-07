# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if(head==None):
            return head
        if(head.next==None):
            return head
        if(head.next.next ==None):
            temp = head.next 
            temp.next = head
            head.next = None
            return temp
        
        P = head.next 
        Q = head.next.next
        head.next = None
        while(Q!=None):
            P.next = head
            head = P
            P = Q
            Q = Q.next
        P.next = head
        return P
        
            
    
            
            
            
            
            
            
        
        
