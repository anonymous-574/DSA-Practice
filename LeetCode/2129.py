class Solution:
    def capitalizeTitle(self, title: str) -> str:
        words=title.split()
        ans=""
        for word in words:
            if len(word)<3:
                ans+=word.lower()+" "
            else:
                ans+=word.capitalize()+" "
        return ans[:-1]