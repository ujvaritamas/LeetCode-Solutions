class Solution:
    def is_palindrome(self, s:str) -> bool:
        return s == s[::-1]

    def longestPalindrome(self, s: str) -> str:
        STRING_SIZE = len(s)
        ret = ""
        palindrome_substring_size = 1
        ret += s[0]
        for i in range(STRING_SIZE):

            if STRING_SIZE - i <= palindrome_substring_size:
                break

            for j in range(STRING_SIZE, i, -1):
                if self.is_palindrome(s[i:j]) and palindrome_substring_size < j-i:
                    ret = s[i:j]
                    palindrome_substring_size = j-i
                    break

        return ret