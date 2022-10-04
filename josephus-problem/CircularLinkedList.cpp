#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

template <typename T> class CircularLinkedList
{
    private:
        int n = 0;
        friend class Node<T>;
        Node<T>* cursor = NULL;
        
    public:
        void append(T data)
        {
            Node<T>* newNode = new Node<T>();
            newNode->data = data;

            if (isEmpty()) { newNode->next = newNode; }
            else {
                newNode->next = cursor->next;
                cursor->next = newNode;
            }

            cursor = newNode;
            n++;
        }
        
        int size()     { return n; }
        bool isEmpty() { return cursor == NULL; }
        
        Node<T>* top() 
        {
            Node<T>* top = cursor->next;
            return top;
        }

        void print()
        {
            Node<T>* p;
            for (p = cursor->next; p != cursor; p = p->next)
                std::cout << p->data << " ";
            std::cout << cursor->data << std::endl;
        }

};