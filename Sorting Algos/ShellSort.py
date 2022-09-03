def shellSort(arr): 
    n = len(arr) 
    gap = n//2
    while gap > 0: 
  
        for i in range(gap,n):  
            temp = arr[i] 
            j = i 
            while  j >= gap and arr[j-gap] >temp: 
                arr[j] = arr[j-gap] 
                j -= gap 
            arr[j] = temp 
        gap //= 2

arr = list(map(int, input('Enter the array to be sorted ').split()))

shellSort(arr)

print('Sorted array')
for i in range(len(arr)):
    print('%d' %arr[i], end = ' ')