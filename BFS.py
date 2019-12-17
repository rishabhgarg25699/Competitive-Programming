class Graph:
    def __init__(self,nodes):
        self.graph=[]
        for i in range(0,nodes):
            self.graph.append([])

    def addedge(self,initial,final):
        (self.graph[initial]).append(final)

# Graph is the adjacency list
    def BFS(self,root):
        visited = []
        bfs = []
        # Using Queue implementation 
        for i in range(0,len(self.graph)):
            visited.append(False)
        bfs.append(root)
        visited[root] = True
        while len(bfs)!=0:
            t = bfs.pop(0)
            # Can change this part to your own convenience
            print(t)
            # Endblock
            if len(self.graph[t])>0:
                for i in self.graph[t]:
                    if visited[i] == False:
                        bfs.append(i)
                        visited[i] = True
            
