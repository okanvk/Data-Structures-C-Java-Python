
adjacency_list = {
    ## first subgraph
    1 : [2,3],
    2 : [1],
    3 : [1,4],
    4 : [6,3],
    5 : [6],
    6 : [5,4],

    ## second subgraph
    7 : [9],
    9 : [7,8],
    8 : [9],

    ## third subgraph
    10 : [12],
    11 : [12,13],
    13 : [11],
    12 : [11,10],

    ##fourth subgraph

    14 : [15],
    15 : [14]
}

from collections import defaultdict

class Graph:
 
    def __init__(self):
        self.graph = defaultdict(list)

    def __init__(self,ds):
      self.graph = ds
 
    def addEdge(self,u,v):
        self.graph[u].append(v)
 
    def BFS(self, s,unique_node_names):
      
        visited = [False] * (max(self.graph) + 1)
        queue = []
  

        queue.append(s)
        visited[s] = True
 
        while queue:

            s = queue.pop(0)
            
            if s != 0:
              unique_node_names.remove(s)

            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

nodes_count = len(list(adjacency_list.keys()))
unique_node_names = list(adjacency_list.keys())
g = Graph(adjacency_list)

def min_bridges(graph,n):
  bridge_count = 0
  while len(unique_node_names) != 0:
    start_node = unique_node_names[0]
    g.BFS(start_node,unique_node_names)
    bridge_count += 1
    

  return bridge_count - 1

min_bridges(adjacency_list,2)

