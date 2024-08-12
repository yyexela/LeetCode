def valueAfterKSeconds(n: int, k: int) -> int:
    old_arr = [1]*n
    new_arr = [1]*n

    for count in range(k):
        old_arr = new_arr
        for i in range(1,n):
            new_arr[i] = (new_arr[i-1] + old_arr[i]) % (10**9 + 7)
    
    return new_arr

print(valueAfterKSeconds(4,5))