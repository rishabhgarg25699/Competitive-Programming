def insertionsort(arr):  
    for i in range(1, len(arr)): 
        key = arr[i]  
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 
  
arr = list(map(int, input('Enter the srray to be sorted ').split())) 

insertionsort(arr) 

print('Sorted array')
for i in range(len(arr)): 
    print ("% d" % arr[i],end = ' ')