def ispal(n):
    return n==n[::-1]
class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans=""
        for i in range(len(s)):
            for j in range(i,len(s)):
                k=s[i:j+1]
                if(ispal(k)):
                    if len(ans)==0:
                        ans=k
                    elif len(k) > len(ans):
                        ans=k    
        return ans
