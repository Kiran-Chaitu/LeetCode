class Solution:
    def isValid(self, word: str) -> bool:
        v,c= 0 ,0
        if not (word.isalnum()) or len(word)<=2:
            return False
        for i in word :
            if i in "aeiouAIEOU" :
                v+=1
            elif i not in "0123456789" :
                c+=1
        return v >=1 and c>=1
        