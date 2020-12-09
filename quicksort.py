a = []


# creating an empty list to store the elements of the quicksort

def partition(a, low, high):
    i = low - 1
    ele = a[high]
    for j in range(low, high):
        if a[j] < ele:
            i = i + 1
            a[j], a[i] = a[i], a[j]
    a[high], a[i + 1] = a[i + 1], a[high]
    return i + 1


# The partition function is used to get the pivotal element and sort in such a way that all the elements to the
#  left of it are less than the pivotal element and all the elements to the right of the pivotal elements are greater than it.

def quicksort(a, low, high):
    if low < high:
        ele = partition(a, low, high)
        quicksort(a, low, ele - 1)
        quicksort(a, ele + 1, high)


# The quicksort function is used to sort the elements to the left and right of the pivotal element which we get after the
# partition function.

print("Enter the value of n to be sorted:")
n = int(input())
print("Enter the {} values to be sorted:".format(n))
for k in range(n):
    u = int(input())
    a.append(u)
quicksort(a, 0, n - 1)
print("The elements after the quick sort are:")
for k in range(n):
    print(a[k])

# This is the main part which pops up on the screen and asks the user to enter the number of elements to be sorted
# & the elements to be actually sorted.

# Example 1
# Enter the value of n to be sorted:
# 7
# Enter the 7 values to be sorted:
# 23
# 65
# 12
# 89
# 4
# 2
# 4
# The elements after the quick sort are:
# 2
# 4
# 4
# 12
# 23
# 65
# 89
# Example 2
# Enter the value of n to be sorted:
# 10
# Enter the 10 values to be sorted:
# 23
# 1
# 67
# 89
# 109
# 4
# 3
# 67
# 54
# 87
# The elements after the quick sort are:
# 1
# 3
# 4
# 23
# 54
# 67
# 67
# 87
# 89
# 109
