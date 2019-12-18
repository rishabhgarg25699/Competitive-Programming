def linear_search(arr, n, x): 
  
    for i in range (0, n): 
        if (arr[i] == x): 
            return i 
    return -1 
  
arr = list(map(int,input('Enter the array: ').split()))
x = int(input('Enter the number to be searched: '))
n = len(arr)
result = linear_search(arr, n, x) 
if(result == -1):
    print("Element is not present in array") 
else: 
    print("Element is present at index", result)