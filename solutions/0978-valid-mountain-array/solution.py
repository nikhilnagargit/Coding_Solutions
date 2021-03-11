class Solution(object):
    def validMountainArray(self, arr):
        i = 0
        flag1 = False
        while(i+1<len(arr) and arr[i]<arr[i+1]):
            flag1 = True
            i+=1
        flag2 = False
        while(i+1<len(arr) and arr[i]>arr[i+1]):
            flag2 =True
            i+=1
            
        if(i==len(arr)-1 and flag1 and flag2):
            return True
        return False
        
