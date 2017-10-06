#!/usr/bin/env python
# -*- coding: utf-8 -*-
'Given a string, find the length of the longest substring without repeating characters.'
class Solution(object):

    def lengthOfLongestSubstring_1(self, s):
        ret = 0
        tmp = ''

        iStart = 0
        iEnd = iStart
        while iEnd < len(s):
            if s[iEnd] in tmp:
                if len(tmp) > retlen:
                    ret = len(tmp)
                iStart = s.index(s[iEnd],iStart,iEnd) + 1
                tmp = s[iStart:iEnd + 1]
            else:
                tmp += s[iEnd]
            iEnd += 1
        if len(tmp) > retlen:
            ret = len(tmp)
        return ret

    def lengthOfLongestSubstring(self, s):
        ret = 0
        iStart = iEnd = 0

        while iEnd < len(s):
            iTmp = s.find(s[iEnd],iStart,iEnd)
            if -1 != iTmp:
                ret = max((iEnd - iStart), ret)#(iEnd - iStart) if (iEnd - iStart) > ret else ret
                iStart = iTmp + 1
            iEnd += 1

        ret = max((iEnd - iStart), ret)#(iEnd - iStart) if (iEnd - iStart) > ret else ret

        return ret

if __name__ == "__main__":
    print Solution().lengthOfLongestSubstring('abcabcbb')


