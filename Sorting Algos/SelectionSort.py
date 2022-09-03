def selectionsort(A): 
    for i in range(len(A)):  
        min_idx = i 
        for j in range(i+1, len(A)): 
            if A[min_idx] > A[j]: 
                min_idx = j         
        A[i], A[min_idx] = A[min_idx], A[i] 

A = list(map(int,input('Enter the array to be sorted here ').split()))

selectionsort(A)

print ('Sorted array') 
for i in range(len(A)): 
    print("%d" %A[i],end = ' ')
