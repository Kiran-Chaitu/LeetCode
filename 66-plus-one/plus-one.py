class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a=0
        for i in digits:
            a=a*10+i
        a+=1
        s=str(a)
        l=[]
        for i in s:
            l.append(int(i))
        return l