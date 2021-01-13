def findMedianSortedArrays(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: float
    """
    while len(nums1) + len(nums2) > 0:
        # Check if there are 2 or 1 numbers left and return median
        if len(nums1) + len(nums2) <= 2:
            print(nums1, nums2)
            count = 0
            num = 0
            for i in range(len(nums1)):
                count += nums1[i]
                num += 1
            for i in range(len(nums2)):
                count += nums2[i]
                num += 1
            return count/(0.0+num) # Only need to add the 0.0 in Python 2.X


        # Pop largest number
        if len(nums1) > 0 and len(nums2) > 0:
            if nums1[-1] > nums2[-1]:
                nums1 = nums1[:-1]
            else:
                nums2 = nums2[:-1]
        elif len(nums1) > 0:
            nums1 = nums1[:-1]
        else:
            nums2 = nums2[:-1]


        # Pop the smallest number
        if len(nums1) > 0 and len(nums2) > 0:
            if nums1[0] < nums2[0]:
                nums1 = nums1[1:]
            else:
                nums2 = nums2[1:]
        elif len(nums1) > 0:
            nums1 = nums1[1:]
        else:
            nums2 = nums2[1:]

    
print(findMedianSortedArrays([1,3,4], [2,4,9]))
print(findMedianSortedArrays([1,3,4,5,6], []))
print(findMedianSortedArrays([], [1,3,4,5,6]))
print(findMedianSortedArrays([1], []))
print(findMedianSortedArrays([], [1]))
print(findMedianSortedArrays([1,2], [3,4]))