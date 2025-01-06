class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        ans = [0]*len(boxes)
        prefixSum = [0]*len(boxes)
        suffixSum = [0]*len(boxes)
        distance = 0
        for i in range(0,len(boxes)):
            if i==0:
                prefixSum[i]=distance
            else:
                prefixSum[i] = distance+prefixSum[i-1]
            if(boxes[i]=='1'):
                distance+=1

        distance = 0

        for i in range(len(boxes)-1,-1,-1):
            if i==len(boxes)-1:
                suffixSum[i]=distance
            else:
                suffixSum[i] = distance+suffixSum[i+1]
            if(boxes[i]=='1'):
                distance+=1

        for i in range(0,len(boxes)):
            ans[i] = prefixSum[i]+suffixSum[i]
        return ans
        
        
