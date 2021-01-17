#Symbol       Value
#I             1
#V             5
#X             10
#L             50
#C             100
#D             500
#M             1000

import unittest

class Solution:

    def getRoman(self, n: int, p: int) -> str:
        """Given an integer of the form n*10^p return its roman numeral"""
        if n == 0:
            return ''
        elif n >= 1 and n <= 3:
            if p == 0:
                return 'I' * n
            elif p == 1:
                return 'X' * n
            elif p == 2:
                return 'C' * n
            elif p == 3:
                return 'M' * n

        elif n == 4:
            if p == 0:
                return 'IV'
            elif p == 1:
                return 'XL'
            elif p == 2:
                return 'CD'
            
        elif n >= 5 and n <= 8:
            if p == 0:
                return 'V' + self.getRoman(n - 5, p)
            elif p == 1:
                return 'L' + self.getRoman(n - 5, p)
            elif p == 2:
                return 'D' + self.getRoman(n - 5, p)

        elif n == 9:
            if p == 0:
                return 'IX'
            elif p == 1:
                return 'XC'
            elif p == 2:
                return 'CM' 

    def intToRoman(self, num: int) -> str:
        # Build result string to 'res'
        res = ''

        # Go through each digit right to left in the input
        # Exponent
        p = 0
        while num > 0:
            digit = num % 10
            num = num // 10
            res = self.getRoman(digit, p) + res
            p += 1

        return res

sol = Solution()

class TestSolution(unittest.TestCase):

    def testAll(self):
        self.assertEqual(sol.intToRoman(1), "I")
        self.assertEqual(sol.intToRoman(2), "II")
        self.assertEqual(sol.intToRoman(12), "XII")
        self.assertEqual(sol.intToRoman(17), "XVII")

#print(sol.convert("PAYPALISHIRING"))
unittest.main()