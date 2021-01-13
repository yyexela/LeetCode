from collections import deque


def findMedianSortedArrays(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: float
    """
    nums1 = deque(nums1)
    nums2 = deque(nums2)
    len1 = len(nums1)
    len2 = len(nums2)
    while True:
        # Check if there are 2 or 1 numbers left and return median
        if len1 + len2 <= 2:
            count = 0
            num = 0
            for i in range(len1):
                count += nums1[i]
                num += 1
            for i in range(len2):
                count += nums2[i]
                num += 1
            return count/(0.0+num) # Only need to add the 0.0 in Python 2.X


        # Pop largest number
        if len1 > 0 and len2 > 0:
            if nums1[-1] > nums2[-1]:
                nums1.pop()
                len1 -= 1
            else:
                nums2.pop()
                len2 -= 1
        elif len1 > 0:
            nums1.pop()
            len1 -= 1
        else:
            nums2.pop()
            len2 -= 1


        # Pop the smallest number
        if len1 > 0 and len2 > 0:
            if nums1[0] < nums2[0]:
                nums1.popleft()
                len1 -= 1
            else:
                nums2.popleft()
                len2 -= 1
        elif len(nums1) > 0:
            nums1.popleft()
            len1 -= 1
        else:
            nums2.popleft()
            len2 -= 1

    
print(findMedianSortedArrays([1,3,4], [2,4,9]))
print(findMedianSortedArrays([1,3,4,5,6], []))
print(findMedianSortedArrays([], [1,3,4,5,6]))
print(findMedianSortedArrays([1], []))
print(findMedianSortedArrays([], [1]))
print(findMedianSortedArrays([1,2], [3,4]))