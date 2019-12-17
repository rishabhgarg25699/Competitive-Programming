class Graph:
    def __init__(self, nodes):
        self.graph=[]
        for i in range(0,nodes):
            self.graph.append([])

    def addedge(self, initial, final, distance):
        # Adding Weights to each direction
        l=[final,distance]
        (self.graph[initial]).append(l)

    def dijkstra(self, root, final):
        info=[]             # Array with defined information for each node
        dij=[]              # Queue to traverse the graph
        # Initializing Info
        for i in range(0,len(self.graph)):
            info.append([100000, False, None])
        dij.append(root)
        info[root][0] = 0
        info[root][1] = True
        while len(dij)!=0:
            t = dij.pop(0)
            dupli = self.graph[t].copy()
            # Sorting duplicate list to make Queue dij a min-priority Queue
            i=len(dupli)-1
            while i>0:
                for j in range(0,i):
                    if dupli[j][1]>dupli[j+1][1]:
                        a = dupli[j][1]
                        dupli[j][1] = dupli[j+1][1]
                        dupli[j+1][1] = a
                i -= 1
            # Checking each direction
            for i in dupli:
                if info[i[0]][0] > info[t][0] + i[1]:
                    info[i[0]][0] = info[t][0] + i[1]
                    info[i[0]][2] = t           # To track the shortest path 
                if info[i[0]][1] == False:      # To not visit one node more than once 
                    dij.append(i[0])
                    info[i[0]][1] = True
        # Printing The path
        x = final
        path=[]
        while x != root:
            path.append(x)
            x = info[x][2]
        path.append(root)
        print(path)
        return info[final][0]
