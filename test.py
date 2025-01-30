import sys

# def twoNumberSum(array, targetSum):
#     # Write your code here.
#     for i in range(len(array)):
#         for j in range(i+1, len(array)):
#             if array[i] + array[j] == targetSum:
#                 return [array[i], array[j]]
#     return []

def twoNumberSum(array, targetSum):
    s = set()
    for num in array:
        if targetSum - num in s:
            return [targetSum-num, num]
        s.add(num)
    return []


# array = [3, 5, -4, 8, 11, 1, -1, 6]
# targetSum = 10
# s = 
array = list(map(int, sys.stdin.readline().strip().split(',')))
targetSum = int(sys.stdin.readline())

print(twoNumberSum(array, targetSum))  # [-1, 11]