class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split()
        ans=""
        for word in words:
            #reverse
            ans+=word[::-1]
            ans+=" "
        #remove last char
        ans = ans[:-1]
        return ans