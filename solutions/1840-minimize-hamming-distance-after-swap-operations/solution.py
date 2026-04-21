class UnionFind:
    def __init__(self,n):
        self.parent = [i for i in range(0,n)]
        self.rank = [0 for _ in range(n)]

    # give the ultimate parent
    def find(self,i):
        if(self.parent[i]==i):
            return i
        # path compression
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self,a,b):
        # find ultimate parent of both and merge small rank under bigger rank
        ap = self.find(a)
        bp = self.find(b)
        if(ap!=bp):
            if(self.rank[ap]>self.rank[bp]):
                # merge bp under ap
                self.parent[bp] = ap
                # rank change
            elif(self.rank[ap]<self.rank[bp]):
                self.parent[ap] = bp
            else:
                self.parent[ap] = bp
                self.rank[bp]+=1


        
class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        # create uf ds
        uf = UnionFind(len(source))
        # fill union find
        mapping = defaultdict(lambda: defaultdict(int))
        for p in allowedSwaps:
            uf.union(p[0],p[1])
        # create maps of each set
        for i in range(len(source)):
            parent = uf.find(i)
            # dict
            mapping[parent][source[i]]+=1
        # loop in tagrt
        ans = 0 
        for i in range(len(target)):
            # check if target exist in union set of corresponding source item
            p= uf.find(i)
            if(mapping[p][target[i]]>0):
                mapping[p][target[i]]-=1
            else:
                ans+=1
        return ans

        
