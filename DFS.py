class Graph:
    def __init__(self,nodes):
        self.graph=[]
        for i in range(0,nodes):
            self.graph.append([])

    def addedge(self,initial,final):
        (self.graph[initial]).append(final)

# Graph is the adjacency list
    def DFS(self,root):
        visited = []
        dfs = []
        # Using Stack Implementation
        for i in range(0,len(self.graph)):
            visited.append(False)
        dfs.append(root)
        visited[root] = True
        while len(dfs)!=0:
            t = dfs.pop(-1)
            # Can change this part to your own convenience
            print(t)
            # Endblock
            if len(self.graph[t])>0:
                for i in self.graph[t]:
                    if visited[i] == False:
                        dfs.append(i)
                        visited[i] = True
            

