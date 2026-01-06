class Node:
    def __init__(self,value:int,key:int):
        self.value = value
        self.key = key
        self.next = None
        self.prev = None


class LRUCache:
    def __init__(self, capacity: int):
        self.left = Node(-1,-1)
        self.right = Node(-1,-1)
        self.left.next = self.right
        self.right.prev = self.left
        self.capacity = capacity
        self.keyToNodeMap = {}

    def insertAtBeginning(self,node:Node):
        temp = self.left.next
        self.left.next = node
        node.next = temp
        temp.prev = node
        node.prev = self.left
    
    def remove(self,node:Node):
        temp = node.prev
        temp.next = node.next
        node.next.prev = temp

    def get(self, key: int) -> int:
        # refresh the key, delete and reinsert in LL
        if key in self.keyToNodeMap:
            node = self.keyToNodeMap[key]
            self.remove(node)
            self.insertAtBeginning(node)
            return node.value
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.keyToNodeMap:
            # remove from ll
            self.remove(self.keyToNodeMap[key])
        # insert in lru
        node = Node(value,key)
        self.keyToNodeMap[key] = node
        # insert in the beginning
        self.insertAtBeginning(node)
        # if capacity is full,remove one node
        if len(self.keyToNodeMap)>self.capacity:
            # identify last node and remove from LL
            lastnode = self.right.prev
            # remove from map
            self.keyToNodeMap.pop(lastnode.key)
            self.remove(lastnode)
        return None
        
        
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
