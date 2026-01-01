class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        idx = len(digits)-1
        while idx>=0 and digits[idx]+carry > 9:
            digits[idx] = 0
            carry = 1
            idx = idx-1
        if idx==-1:
            digits.insert(0,1)
        else:
            digits[idx] = digits[idx]+carry
        return digits
        
