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
   
arr = list(map(int,input('Enter the array: ').split()))
x = int(input('Enter the number to be searched: '))
n = len(arr)

result = int(jump_search(arr, x, n)) 
  
if(result == -1):
    print("Element is not present in array") 
else: 
    print("Element is present at index", result)