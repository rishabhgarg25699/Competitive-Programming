def interpolation_search(arr, n, x):  
    lo = 0
    hi = (n - 1)  
    while lo <= hi and x >= arr[lo] and x <= arr[hi]: 
        if lo == hi: 
            if arr[lo] == x:  
                return lo
            return -1 
           
        pos  = lo + int(((float(hi - lo) / 
            ( arr[hi] - arr[lo])) * ( x - arr[lo]))) 

        if arr[pos] == x: 
            return pos 
        if arr[pos] < x: 
            lo = pos + 1
        else: 
            hi = pos - 1 
      
    return -1
   
arr = list(map(int,input('Enter the array: ').split()))
x = int(input('Enter the number to be searched: '))
n = len(arr)
index = interpolation_search(arr, n, x) 
  
if index != -1: 
    print("Element found at index",index) 
else: 
    print("Element not found")