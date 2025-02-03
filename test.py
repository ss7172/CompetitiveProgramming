import sys
from typing import List

# s = sys.stdin.readline().strip(',')
# print(s)
# print(list(int(s)))
# array = list(map(int, s))
a = list(map(int, sys.stdin.readline().split(',')))
# print(a)
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        l = []
        for num in nums:
            l.append(num)
        for num in nums:
            l.append(num)
            
        return l

c = Solution()
print(c.getConcatenation(a))

