import math 
  
def jump_search( arr , x , n ):  
    step = math.sqrt(n)  
    prev = 0
    while arr[int(min(step, n)-1)] < x: 
        prev = step 
        step += math.sqrt(n) 
        if prev >= n: 
            return -1
       
    while arr[int(prev)] < x: 
        prev += 1 
        if prev == min(step, n): 
            return -1
    
    if arr[int(prev)] == x: 
        return prev 
      
    return -1
   
arr = [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 ] 
x = 55
n = len(arr) 

result = int(jump_search(arr, x, n)) 
  
if(result == -1):
    print("Element is not present in array") 
else: 
    print("Element is present at index", result)