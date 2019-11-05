
class Node:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def add(self,node):
        if self.root == None:
            self.root = node
        else:
            self.recursive_add(self.root,node)

    def recursive_add(self,current,node):
        if node.key < current.key:
            if current.left != None:
                self.recursive_add(current.left,node)
            else:
                current.left = node
        elif node.key > current.key:
            if current.right != None:
                self.recursive_add(current.right,node)
            else:
                current.right = node
        else:
            print('error the node currently exists')

    def print_tree(self):
        self.recursive_print(self.root)

    def recursive_print(self,current):
        if current.left != None:
            self.recursive_print(current.left)

        print(current.key,end=',')

        if current.right != None:
            self.recursive_print(current.right)

tree = BST()
tree.add(Node(5))
tree.add(Node(7))
tree.add(Node(6))
tree.add(Node(13))
tree.add(Node(3))
tree.print_tree()
