class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)
def del_max_node(node):
    root = node #preserving the root of the tree
    while (node.right.right != None):
        node = node.right
    #now node is the parent node of the max node
    #we will now delete this max node:
    if node.right.left == None:
        node.right = None
    else:
        node.right = node.right.left
    return root
def third_largest(node):
    root = del_max_node(node)
    root = del_max_node(node)
    #2 largest nodes have been deleted now
    while (root.right != None):
        root = root.right
    return root.value
'''
this function runs in O(h) time because in the worst case, the complexity is O(3h), which is O(h)
root = BST(4)
root.insert(2)
root.insert(3)
root.insert(5)
root.insert(7)
root.insert(6)
root.insert(8)
root.insert(9)
root.insert(10)
root.insert(69)
root.insert(11)
print(third_largest(root))
'''