from collections import deque

def reverse(x):
    negative = False # Keep track of negative values
    x = str(x) # Convert int to string
    if(x[0] == '-'): # Check if value is negative
        negative = True
    x = deque(list(str(x))) # Create list of values of string
    x.reverse() # Swap them
    if(negative): # Handle negative
        x.pop()
        x.appendleft("-")
    x = int(''.join(x)) # Convert to int
    if(x < -2**31 or x > 2**31 - 1):
        return 0
    else:
        return x

print(reverse(-12345))