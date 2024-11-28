import numpy as np
class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        if (m*n) != len(original):
            return []
        arr=np.array(original)
        arr=arr.reshape(m,n)
        return arr.tolist()
        
        