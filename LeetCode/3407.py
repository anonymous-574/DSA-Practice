class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        p = p.split("*")     
        left=s.find(p[0])
        right=s.find(p[1], left+len(p[0]))

        return left!=-1 and right!=-1