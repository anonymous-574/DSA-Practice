class Solution(object):
    def sortSentence(self, s):
        """
        :type s: str
        :rtype: str
        """
        words=s.split()
        words.sort(key=lambda x:x[-1])
        return ' '.join([word[:-1] for word in words])