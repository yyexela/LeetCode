class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Convert int to string
        s = str(x)

        # Indices for checking if palindrome
        left = 0
        right = len(s) - 1

        # Check if int is palindrome
        while left <= right and s[left] == s[right]:
            left += 1
            right -= 1
        
        if left < right:
            return False
        else:
            return True


sol = Solution()
print(sol.isPalindrome(213212))