#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution(object):

    def __init__(self):
        pass

    def twoSum_1(self, nums, target):
        for i in xrange(len(nums)):
            for j in xrange(len(nums[i+1:])):
                if nums[i] + nums[j] == target:
                    return(i,j)
    def twoSum(self, nums, target):
        d = {}
        for i in xrange(len(nums)):
            x = nums[i]
            if target - x in d:
                return (d[target - x],i)
            d[x] = i

if __name__ == "__main__":
    sol = Solution()
    print sol.twoSum([2, 7, 11, 15], 9)
