def binary_search (arr, l, r, x): 
    if r >= l: 
        mid = int(l + (r - l)/2)  
        if arr[mid] == x: 
            return mid 
        elif arr[mid] > x: 
            return binary_search(arr, l, mid-1, x) 
        else: 
            return binary_search(arr, mid + 1, r, x)   
    else: 
        return -1
 
arr = list(map(int,input('Enter the array: ').split()))
x = int(input('Enter the number to be searched: '))
result = binary_search(arr, 0, len(arr)-1, x) 
  
if result != -1: 
    print("Element is present at index",result) 
else: 
    print("Element is not present in array")