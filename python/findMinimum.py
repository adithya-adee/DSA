def find_minimum(nums):
    minimum = float("inf")

    for i in nums:
        if i < minimum:
            minimum = i

    return minimum


def find_max(nums):
    maximum = float("-inf")
    for i in nums:
        if i > maximum:
            maximum = i

    return maximum


def find_max_two_pointer(nums):
    maximum = float("-inf")
    for i in nums:
        if i > maximum:
            maximum = i

    return maximum
