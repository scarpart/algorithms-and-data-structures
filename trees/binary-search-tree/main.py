from BinarySearchTree import BinarySearchTree

bst = BinarySearchTree()

bst.insert(89)
bst.insert(7)
bst.insert(76)
bst.insert(94)
bst.insert(1)
bst.insert(100)
bst.insert(90)

print("Inorder: ", end="")
bst.inorder()

print("Postorder: ", end="")
bst.postorder()

print("Preorder: ", end="")
bst.preorder()