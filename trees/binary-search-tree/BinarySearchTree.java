

public class BinarySearchTree
{
    private class Node
    {
        Node right = null;
        Node left = null;
        int val;
    }

    private Node root = null;

    /**
     *  Searches for node with value x
     *  
     *  @param x value to be searched for
     *  @param pivot starting search node 
     *  @return the node containing the value if it exists,
     *          otherwise returns the parent node to where that node would be.
     */
    private Node search(int x, Node pivot)
    {
        if (x == pivot.val)
            return pivot;
        else
        {
            if (x >= pivot.val)
                if (pivot.right != null)
                    return search(x, pivot.right);
            else
                if (pivot.left != null)
                    return search(x, pivot.left);
        }
        return pivot;
    }

    /**
     * Using the search method, inserts a new Node onto the tree
     * 
     * @param x integer value to be added
     */
    public void insert(int x)
    {
        Node newNode = new Node();
        newNode.val = x;
        if (root == null)
            root = newNode;
        else
        {
            Node pivot = search(x, root);
            //System.out.printf("\nIn insert's else: pivot.val = %d\n", pivot.val);
            if (x <= pivot.val) {
                pivot.left = newNode;
                //System.out.printf("Inserting on pivot.left = %d\n", pivot.left.val);
                //System.out.printf("Pivot.val left of root = %d\n", root.left.val);
            }
            else {
                pivot.right = newNode;
                //System.out.printf("Inserting on pivot.right = %d\n", pivot.right.val);
            }
        }
    }

    private void stringInorder(Node pivot)
    {
        if (pivot != null)
        {
            stringInorder(pivot.left);
            System.out.printf("%d ", pivot.val);
            stringInorder(pivot.right);
        }
    }

    public void inorder()
    {
        stringInorder(root);
        System.out.println();
    }

}