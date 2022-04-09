Inf = float('inf')
graph = [
        [0,6,11,Inf,-1],
        [Inf,0,Inf,4,10],
        [Inf,7,0,Inf,Inf],
        [5,Inf,-2,0,Inf],
        [Inf,Inf,Inf,9,0]
    ]
V = len(graph)


def FindShortestPath(graph):

    dist_matrix = list(map(lambda i: list(map(lambda j: j, i)), graph))
    for k in range(V):
         for i in range(V):
            for j in range(V):
                dist_matrix[i][j] = min(dist_matrix[i][j],dist_matrix[i][k] + dist_matrix[k][j])    
                printSolutionSteps(dist_matrix)
    printTotalWeights(dist_matrix)


def printSolutionSteps(dist_matrix):
    print ("Print Solution Steps")
    for i in range(V):
        for j in range(V):
            if(dist_matrix[i][j] == Inf):
              print(f"INF\t",end = " ")
            else:
              print(f"{dist_matrix[i][j]}\t",end = " ")
            if j == V-1:
              print(end="\n")

def printTotalWeights(dist_matrix):
    print ("Total Weights of Shortest Paths")
    for i in range(V):
        for j in range(V):
            if i != j:
              print(f'The shortest path from {i+1} —> {j+1} :', dist_matrix[i][j])

FindShortestPath(graph)
