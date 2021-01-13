def myAtoi(s):
    """
    :type s: str
    :rtype: int
    """
    s = s.strip() # Remove white space
    if len(s) <= 0:
        return 0
    if s[0] == '-' or s[0] == '+':
        s1 = s[0]
        s = s[1:]
    else:
        s1 = ''
    for c in s:
        try:
            int(c)
            s1 += c
        except ValueError:
            print(c, "Not an int")
            break
    if s1 == '':
        return 0
    i1 = 0
    try:
        i1 = int(s1)
    except ValueError:
        i1 = 0
    if i1 > 2**31 - 1:
        return 2**31 - 1
    elif i1 < -2**31:
        return -2**31
    return i1


print(myAtoi("+-12"))