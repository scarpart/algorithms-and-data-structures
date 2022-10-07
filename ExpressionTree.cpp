#include <string.h>
#include <map>

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
    int assignment = 0;

    std::map<int, std::string> mapOperands()
    {
        std::map<int, std::string> m;
        std::string operands = "-+/*";
        for (int i = 0; i < 4; i++)
            m[i] = operands[i];
        return m;
    }

    public:

    void createTree(std::string s, Node* node)
    {
        printf("\nSTRING---> %s\n", s.c_str());
        
        if (s.length() == 0) return;

        if (node == NULL) 
            node = new Node();

        if (root == NULL) 
            root = node;

        for (int i = 0; i < 4; i++)
        {
            if (s.find(m[i]) != std::string::npos)
            {
                printf("inside if on for\n");
                int index = s.rfind(m[i]);
                node->val = s[index];
                std::string right = s.substr(index+1);
                std::string left = s.substr(0, index);
                createTree(right, node->right);
                createTree(left, node->left);
                break;
            }
            node->val = s;
            break;
        }

    }
        
    void postfix(Node* node)
    {
        if (node == NULL && !assignment) {
            node = root;
            assignment = 1;
        }
        
        if (node != NULL) {
            postfix(node->left);
            postfix(node->right);
            printf("%s", node->val.c_str());
        } else {
            printf("\n");
        }
    }

    void prefix(Node* node)
    {     
        if (node == NULL && !assignment) {
            node = root;
            assignment = 1;
        }

        if (node != NULL) {
            printf("%s", node->val.c_str());
            prefix(node->left);
            prefix(node->right);
        } else {
            printf("\n");
            return;
        }
    }

    Node* get_root()
    {
        return root;
    }

};