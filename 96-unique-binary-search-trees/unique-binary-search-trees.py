
def fact(n):
        p=1
        for i in range(2,n+1):
            p*=i
        return p
class Solution:
    
    def numTrees(self, n: int) -> int:
        ans = (fact(2*n)//(fact(n)*fact(n+1)))
        return ans