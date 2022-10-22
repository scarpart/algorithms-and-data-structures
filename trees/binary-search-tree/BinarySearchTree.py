

class BinarySearchTree():
    
    class Node():
        def __init__(self, val):
            self.right = None
            self.left = None
            self.val = val

    def __init__(self):
        self.root = None

    def search(self, x:int, pivot:Node) -> Node:
        if x == pivot.val:
            return pivot
        else:
            if x >= pivot.val:
                if pivot.right is not None:
                    return self.search(x, pivot.right)
            else:
                if pivot.left is not None:
                    return self.search(x, pivot.left)
        return pivot
    
    def insert(self, x:int):
        new_node = self.Node(x)
        if self.root is None:
            self.root = new_node
        else:
            pivot = self.search(x, self.root)
            if x <= pivot.val:
                pivot.left = new_node
            else:
                pivot.right = new_node

    def __string_inorder(self, pivot:Node):
        if pivot is not None:
            self.__string_inorder(pivot.left)
            print(pivot.val, end=" ")
            self.__string_inorder(pivot.right)

    def __string_preorder(self, pivot:Node):
        if pivot is not None:
            print(pivot.val, end=" ")
            self.__string_preorder(pivot.left)
            self.__string_preorder(pivot.right)
    
    def __string_postorder(self, pivot:None):
        if pivot is not None:
            self.__string_postorder(pivot.left)
            self.__string_postorder(pivot.right)
            print(pivot.val, end=" ")

    def inorder(self):
        self.__string_inorder(self.root)
        print()

    def preorder(self):
        self.__string_preorder(self.root)
        print()
    
    def postorder(self):
        self.__string_postorder(self.root)
        print()
