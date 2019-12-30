#Implementation of count sort(O(n))
def countsort(A,B,C,k):
    for i in range(k):
        C[i]=0
    for q in range(len(A)):
        C[A[q]]=C[A[q]]+1
       #C[i] contains no. of elemeents equal to i   
    for p in range(k):
        if p==0:
            continue
        else:
            C[p]=C[p]+C[p-1]    
        #C[i]now contains the number of elemnmtss less than or equal to i
    for j in range(len(A)):
          B[C[A[j]]-1] = A[j]
          C[A[j]] = C[A[j]]-1       

#Driver Code
n=int(input("Enter range: "))  #Taking the range as input
A=[int(x) for x in input(('Enter whole numbers less than %d :'%(n))).split()]#Inputting the sequence to be sorted
B=[0]*len(A)
C=[0]*n
countsort(A,B,C,n)
print(B)#Outputting
