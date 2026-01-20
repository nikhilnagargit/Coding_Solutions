class Solution:
    def reverseWords(self, s: str) -> str:
        l = list(filter(lambda x: x!="",[item for item in list(s.split(' '))]))
        l.reverse()
        return " ".join(l)
