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
        void Insert(T data)
        {
            Node<T>* newNode = new Node<T>();
            newNode->data = data;
            if (IsEmpty()) { newNode->next = newNode; }
            else {
                newNode->next = cursor->next;
                cursor->next = newNode;
            }
            cursor = newNode;
            n++;
        }
        
        void Remove(int index)
        {
            Node<T>* p = cursor;
            int i;
            for (i = 0; i < index; i++)
                p = p->next;
                
            if (Size() == 1) {
                cursor = NULL;
                delete p;
            } else {
                Node<T>* removed = p->next;
                if (Size() - 1 == index)
                    cursor = p;
                p->next = removed->next;
                delete removed;
            }
            
            n--;
        }
        
        int Size()     { return n; }
        bool IsEmpty() { return cursor == NULL; }
        
        T Top() 
        {
            Node<T>* top = cursor->next;
            return top->data;
        }

        void Print()
        {
            Node<T>* p;
            for (p = cursor->next; p != cursor; p = p->next)
                std::cout << p->data << " ";
            std::cout << cursor->data << std::endl;
        }

};

