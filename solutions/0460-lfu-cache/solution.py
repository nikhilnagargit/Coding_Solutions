class Node:
    def __init__(self,key:int,value:int):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LinkedList:
    def __init__(self):
        self.left = Node(-1,-1)
        self.right = Node(-1,-1)
        self.left.next = self.right
        self.right.prev = self.left
    
    def insertAtBeginning(self,node:Node):
        temp = self.left.next
        self.left.next = node
        node.next = temp 
        temp.prev = node
        node.prev = self.left
    
    def removeLastNode(self)->Node:
        if self.right.prev.prev == None:
            return None
        node = self.right.prev
        return self.removeNode(node)

    def removeNode(self,node)->Node:
        temp = node.prev
        temp.next = node.next
        node.next.prev = temp
        node.next = None
        return node

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.countListMap = defaultdict(lambda:LinkedList())
        self.counter = 1
        self.keyNodeMap = {}
        self.keyCountMap = {}
    
    def get(self, key: int) -> int:
        # print(self.keyNodeMap)
        # if key does not exist
        if key not in self.keyNodeMap:
            return -1
        # if key exists return value, but update things
        # update the counter for that node
        node = self.keyNodeMap[key]
        count = self.keyCountMap[key]
        newCount = count+1
        self.countListMap[count].removeNode(node)
        self.countListMap[newCount].insertAtBeginning(node)
        self.keyCountMap[key]=newCount
        return self.keyNodeMap[key].value


    def put(self, key: int, value: int) -> None:
        #handle base case
        if(self.capacity==0):
            return

        # if key is not present, add new key, set the counter to 1
        if key not in self.keyNodeMap:
            # if you inserted new item, we need to check first for capacity and if capacity exceeds, we need to remove least frequent item from counter variable count which signify least recent
            if self.capacity == len(self.keyNodeMap):
                # remove one least frequently used item
                node = self.countListMap[self.counter].removeLastNode()
                while(node==None):
                    self.counter = self.counter+1
                    node = self.countListMap[self.counter].removeLastNode()
                self.keyNodeMap.pop(node.key)
                self.keyCountMap.pop(node.key)
            # node insert the new item
            self.counter = 1
            node = Node(key,value)
            self.countListMap[1].insertAtBeginning(node)
            self.keyCountMap[key]=1
            self.keyNodeMap[key]=node

        else:
            # if key was present, we need to update counter for that updated value and update the value
            count = self.keyCountMap[key]
            node = self.keyNodeMap[key]
            node.value = value
            self.countListMap[count].removeNode(node)
            newCount = count+1
            self.keyCountMap[key] = newCount
            # need to check if new count key's linkedlist is there
            self.countListMap[newCount].insertAtBeginning(node)
    
