class graphs:
    def __init__(self, n):
        self.adjacency_matrix = ([0] * n) * n
    def addEdge(self, fromVertex, toVertex, weight):
        self.adjacency_matrix[fromVertex][toVertex] = weight
    def isEdge(self, fromVertex, toVertex):
        if self.adjacency_matrix[fromVertex][toVertex] == 0:
            return False
        return True
    def shortestPath(self, fromVertex, toVertex):
        temp = djikstra(fromVertex)
        for i in range(len(temp[1])):
            if temp[1][i] == toVertex:
                return temp[0][i]