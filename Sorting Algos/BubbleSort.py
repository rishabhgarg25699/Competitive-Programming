def bubbleSort(arr): 
    n = len(arr)  
    for i in range(n):  
        for j in range(0, n-i-1):  
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
  
arr = list(map(int, input('Enter the array to be sorted ').split())) 
  
bubbleSort(arr) 
  
print ("Sorted array") 
for i in range(len(arr)): 
    print ("%d" %arr[i],end = ' ')