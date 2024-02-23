from math import factorial
class Solution:
    def countOrders(self, n: int) -> int:
        return ((factorial(2*n))//(2**n))%(1000000007)