import unittest

class Solution:
    def convert(self, s: str, numRows: int) -> str:

        # Create a list with numRows strings, one for each row of the zig zag
        rows = []
        for _ in range(numRows):
            rows.append('')

        numRowsMinusOne = numRows - 1 # Performance improvement
        pos= 0 # Keep track of which row we are at for the zig zag
        dir = 0 # Keep track of zig zag direction, 0 means down, 1 means up

        # Construct zig zag
        for i in range(len(s)):
            rows[pos] = rows[pos] + s[i] # Add character to current row string

            # Check current position
            if pos >= numRowsMinusOne:
                dir = 1 # Go down
            elif pos <= 0:
                dir = 0 # Go up

            # Move to next row
            if not dir:
                pos += 1
            else:
                pos -= 1

        # Construct resulting string
        res = ''
        for i in range(numRows):
            res += rows[i]
        
        return res

sol = Solution()

class TestSolution(unittest.TestCase):

    def testGiven(self):
        self.assertEqual(sol.convert("PAYPALISHIRING",3), "PAHNAPLSIIGYIR")

    def testGiven2(self):
        self.assertEqual(sol.convert("PAYPALISHIRING",4), "PINALSIGYAHRPI")

    def testGiven3(self):
        self.assertEqual(sol.convert("A",1), "A")

#print(sol.convert("PAYPALISHIRING", 3))
unittest.main()