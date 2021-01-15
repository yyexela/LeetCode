class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Current max string palindrome length
        size = 1
        # Index of current max palindrome
        index = 0
        # Defaults to first character, size 1

        # Loop through each character left to right
        for i in range(len(s)):
            # Loop backwards through the string searching 
            for j in reversed(range(i+size,len(s),1)):
                # Perform stirng check
                p = i
                q = j
                # Check for palindrome
                while s[p] == s[q] and p <= q:
                    p += 1
                    q -= 1

                # Check if we found a palindrome
                if p > q and size < j - i + 1:
                    index = i
                    size = j - i + 1

        return s[index:index+size]
        

# abad
s = Solution()
print("Longest palindrome:", s.longestPalindrome("abadaba"))
