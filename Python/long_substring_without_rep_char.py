class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret_num = 0
        ret_s = ""
        size = len(s)
        for i in range(size):
            visited_char = {}
            visited_char[s[i]]= True
            temp_num = 1
            temp_s = ""
            temp_s += s[i]
            for j in range(i+1, size):
                if s[j] in visited_char:
                    break
                else:
                    visited_char[s[j]]= True
                    temp_s += s[j]
                    temp_num+=1
            if temp_num > ret_num:
                ret_num = temp_num
                ret_s = ""
                ret_s += temp_s

        return ret_num


