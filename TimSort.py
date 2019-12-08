# Sorting an array using Tim Sort
def TimSort(l):
    # Divided into different groups each having length equal to some power of 2
    x=ConvBinary(len(l))
    for i in range(0,len(x)):
        x[i]=x[i]*Power2(i)
    y=[]
    for i in x:
        if i!=0:
            y.append(i)
    x.clear()
    # If the length of l is a not a power of 2
    if len(y)>1:
        x=[0]
        for i in y:
            a=x[-1] + i
            x.append(a)
        final=[]
        for i in range(0,len(x)-1):
            m=[]
            m = l[x[i]:x[i+1]:1] # Slicing to get all groups 
            final.append(m)
        n=[]
        for p in final:
            n.append(InsertionS(p)) # Applying insertion_sort to each group 
        while len(n)>1:
            n.append(merge(n.pop(0),n.pop(0))) # Merging all sorted groups
    # If the length of l is a power of 2
    else:
        n=[]
        n.append(merge([l[0]],TimSort(l[1::1]))) # Dividing into 2 groups
    fin = n[0]
    return fin
        

def ConvBinary(n):
    i=0
    x=[]
    while n>0:
        m = n%2
        x.append(m)
        n=int(n/2)
    return x

def Power2(n):
    z=1
    if n==0:
        z=1
    else:
        for i in range(0,n):
            z=2*z
    return z
def InsertionS(l):
    if len(l)>1:
        for i in range(1,len(l)):
            a=l[i]
            j=i-1
            while j>=0 and a<l[j]:
                l[j+1] = l[j]
                j -= 1
            l[j+1] = a
    return(l)
def merge(a,b):
    running = True
    i=0
    j=0
    c=[]
    while running:
        if i!=len(a) and j!=len(b):
            if a[i]<b[j]:
                c.append(a[i])
                i += 1
            else:
                c.append(b[j])
                j += 1
        else:
            if i==len(a):
                while j<len(b):
                    c.append(b[j])
                    j += 1
                    running = False
            else:
                while i<len(a):
                    c.append(a[i])
                    i += 1
                    running = False
    return c
        
    
