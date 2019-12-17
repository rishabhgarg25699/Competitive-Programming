class Graph:
    def __init__(self,nodes):
        self.graph=[]
        for i in range(0,nodes):
            self.graph.append([])

    def addedge(self,initial,final):
        (self.graph[initial]).append(final)

    def TopoSort(self):
        # To create an array which keeps track of every node's degree
        degree=[]
        for i in range(0,len(self.graph)):
            degree.append(0)
        for j in self.graph:
            for k in j:
                degree[k] += 1
        # To remove one element one by one to get a topological order
        final=[]
        while len(final)<len(self.graph):
            for l in range(0,len(degree)):
                if degree[l] == 0 and l not in final:
                    final.append(l)
                    for m in self.graph[l]:
                        # To incorporate the change in degree array
                        degree[m] -= 1
                    # To reduce number of unnecessary loops
                    break
        print(final)
       


