#include <string.h>
#include <map>
#include <iostream>

class Node
{
    public:
        std::string val;
        Node* left = NULL;
        Node* right = NULL;
};

class ExpressionTree
{
    private:
    
    std::map<int, std::string> m = mapOperands();
    friend class Node;
    Node* root = NULL;

    std::map<int, std::string> mapOperands()
    {
        std::map<int, std::string> m;
        std::string operands = "-+*/";
        for (int i = 0; i < 4; i++)
            m[i] = operands[i];
        return m;
    }
    
    void getPostfix(Node* node, std::string *s)
    {
        if (node != NULL) {
            getPostfix(node->left, s);
            getPostfix(node->right, s);
            (*s).append(node->val);
        } 
    }

    void getPrefix(Node* node, std::string *s)
    {     
        if (node != NULL) {
            (*s).append(node->val);
            getPrefix(node->left, s);
            getPrefix(node->right, s);
        } 
    }

    void getInfix(Node* node, std::string *s)
    {
        if (node != NULL) {
            getInfix(node->left, s);
            (*s).append(node->val);
            getInfix(node->right, s);
        }
    }

    public:

    void createTree(std::string s, Node* node)
    {
        if (node == NULL) 
            node = new Node();

        if (root == NULL)  
            root = node;
        
        if (s.length() == 1) {
            node->val = s;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            if (s.find(m[i]) != std::string::npos)
            {
                int index = s.rfind(m[i]);
                node->val = s[index];
                std::string right = s.substr(index+1);
                std::string left = s.substr(0, index);

                Node* rightNode = new Node();
                node->right = rightNode;
                Node* leftNode = new Node();
                node->left = leftNode;

                createTree(right, rightNode);
                createTree(left, leftNode);
                return;
            }
        
        }

    }

    std::string postfix()
    {
        std::string s;
        getPostfix(root, &s);
        return s;
    }

    std::string prefix()
    {
        std::string s;
        getPrefix(root, &s);
        return s;
    }

    std::string infix()
    {
        std::string s;
        getInfix(root, &s);
        return s;
    }

};
