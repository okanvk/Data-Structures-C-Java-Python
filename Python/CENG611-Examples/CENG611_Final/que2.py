from random import seed
from random import randint
seed(42)



class Graph():

    def __init__(self):
        self.graph = []

    def isBipartite(self):

        V = len(self.graph)
        rand_node_index = randint(0, V-1) 

        colorArr = [-1] * V
        colorArr[rand_node_index] = 1

        queue = []
        queue.append(rand_node_index)

        while queue:
            u = queue.pop()
            if self.graph[u][u] == 1:
                return False;

            for v in range(V):

                if self.graph[u][v] == 1 and colorArr[v] == -1:
                    colorArr[v] = 1 - colorArr[u]
                    queue.append(v)
                elif self.graph[u][v] == 1 and colorArr[v] == colorArr[u]:
                    return False
        return True

g = Graph()
g.graph = [[0,1,1,0,0],
           [1,0,0,1,0],
           [1,0,0,1,0],
           [0,0,1,0,1],
           [0,1,0,1,0]
            ]
            
print(g.isBipartite())

g.graph = [[0, 1, 0, 1],
            [1, 0, 1, 0],
            [0, 1, 0, 1],
            [1, 0, 1, 0]
            ]
print(g.isBipartite())
