''' 
Given a non-negative integer numRows,generate the first numRows of Pascal's triangle.
pascal's triangle :https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif

'''

numRows=int(input())
if(numRows==0):
    print([])
elif(numRows==1):
    print([[1]])
else:
    l=[[1],[1,1]]
    for i in range(2,numRows):
        l1=[1]
        for j in range(1,i):
            l1.append(l[i-1][j-1]+l[i-1][j])
        l1.append(1)
        l.append(l1)
    print(l)
        
'''
Input: 5
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
'''