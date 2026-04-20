# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # i will create a heap, which have the size of lists=k, we keep first smallest nodes of each lists in that heap
        # we process the smallest value of node, we pop it, and push next node of that popped node in heap
        # we keep merging the nodes and after anothers by poppin from heap
        # we do this until heap become empty
        dummy = ListNode()
        curr = dummy
        minheap = []
        # put first nodes in min heap -> (node value, node) 
        idx = 0
        for l in lists:
            if l:
                heapq.heappush(minheap,(l.val,idx,l))
                idx+=1
        # start poppin until minheap become empty

        while len(minheap)>0:
            # take the smallest one and pop
            item = heapq.heappop(minheap)
            curr.next = item[2]
            curr = curr.next
            # put the next node in heap, if exist
            if curr.next:
                heapq.heappush(minheap,(curr.next.val,idx,curr.next))
                idx+=1
        return dummy.next



        



        
