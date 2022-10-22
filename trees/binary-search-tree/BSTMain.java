

public class BSTMain
{
    public static void main(String[] args)
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(89);
        bst.insert(7);
        bst.insert(76);
        bst.insert(94);
        bst.insert(1);
        bst.insert(100);
        bst.insert(90);
        bst.inorder();
    }
}