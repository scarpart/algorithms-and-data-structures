#include <iostream>

class Node
{
    public:
    Node* right = NULL;
    Node* left = NULL;
    int val;
};

class BinarySearchTree
{
    private:

    Node* root = NULL;

    void stringInorder(Node* pivot)
    {
        if (pivot != NULL)
        {
            stringInorder(pivot->left);
            std::cout << pivot->val << " ";
            stringInorder(pivot->right);
        }
    }

    Node* search(int x, Node* pivot)
    {
        if (x == pivot->val)
            return pivot;
        else
        {
            if (x >= pivot->val)
                if (pivot->right != NULL)
                    return search(x, pivot->right);
            else 
                if (pivot->left != NULL)
                    return search(x, pivot->left);
        }
        return pivot;
    }

    public:

    void insert(int x)
    {
        Node* newNode = new Node();
        newNode->val = x;
        if (root == NULL)
            root = newNode;
        else
        {
            Node* pivot = search(x, root);
            
            if (x <= pivot->val)
                pivot->left = newNode;
            else
                pivot->right = newNode;
        }
    }

    void inorder()
    {
        stringInorder(root);
        std::cout << std::endl;
    }

};