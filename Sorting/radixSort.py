def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n  # output array
    count = [0] * 10  # for digits 0 to 9

    # Store count of occurrences of digits
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    # Update count[i] so that count[i] contains actual
    # position of this digit in output[]
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array (stable sort)
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # Copy the output array to arr[], so that arr now
    # contains sorted numbers according to current digit
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    # Find the maximum number to know the number of digits
    max_num = max(arr)

    # Do counting sort for every digit.
    exp = 1  # Exponent: 1, 10, 100, ...
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

# Example usage
arr = [170, 45, 75, 90, 802, 24, 2, 66]
print("Original array:", arr)
radix_sort(arr)
print("Sorted array:  ", arr)