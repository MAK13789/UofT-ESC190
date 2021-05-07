import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False


def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})


def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


################################################################################

def get_all_nodes(node):
    '''Return a list of the nodes in the graph of nodes connected to node
    (N.B., the nodes can be indirectly connected as well)'''
    q = [node]
    node.visited = True
    connected_nodes = []
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                connected_nodes.append(con['node'])
                con["node"].visited = True
    return connected_nodes


################################################################################

def unvisit_all(node):
    '''Change all n.visited to False in all the nodes in the graph of nodes
    connected to node. Use BFS to find all the nodes'''
    node_list = [node]
    while len(node_list) > 0:
        cur = node_list.pop(0)
        for con in cur.connections:
            if con['node'].visited:
                node_list.append(con['node'])
                con['node'].visited = False





###############################################################################

def DFS_rec(node):
    '''Print out the names of all nodes connected to node using a
    recursive version of DFS'''
    node.visited = True
    for con in reversed(node.connections):
        if not con['node'].visited:
            print (con['node'].name)
            DFS_rec(con['node'])



################################################################################
def DFS_nonrec(node):
    '''Print out the names of all nodes connected to node using a non-recursive
    version of DFS. Make it so that the nodes are printed in the same order
    as in DFS_rec'''
    stack = [node]
    node.visited = True
    while len(stack) > 0:
        cur = stack.pop(-1) 
        if cur != node:
            print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                stack.append(con["node"])
                con["node"].visited = True





################################################################################
#
# OPTIONAL
#

def dijsktra_slowish(node):
    '''Implement Dijkstra's algorithm as discussed in class (i.e., you don't
    need to use a priority queue'''
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    while len(unexplored) > 0:
        # your code here
        pass

    return d




if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")
    TEMP = Node("sfsf")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)
    L = get_all_nodes(TO)
    unvisit_all(TO)
    DFS_nonrec(TO)
    unvisit_all(TO)
    DFS_rec(TO)     
    #print(dijsktra_slowish(TO))