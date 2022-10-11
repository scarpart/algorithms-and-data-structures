#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

template <typename T> class Queue
{
    private:
        friend class Node<T>;
        Node<T>* head = NULL;
        Node<T>* last = NULL;
        int n = 0; /* keeps track of the queue size */

    public:
        void enqueue(T data)
        {
            if (!isEmpty()) {
                Node<T>* newNode = new Node<T>();
                newNode->data = data;
                newNode->next = last->next;
                last->next = newNode;
                last = newNode;
            } else {
                last = head = new Node<T>();
                head->data = data;
                head->next = NULL;
            }
            n++;
        }

        T dequeue()
        {
            if (!isEmpty()) {
                Node<T>* oldhead = head;
                T data = oldhead->data;
                head = oldhead->next;
                delete oldhead;
                n--;
                return data;
            }

            return 0;
        }

        bool isEmpty()
        {
            return (head == NULL);
        }

        int size()
        {
            return n;
        }
        
        void print()
        {
            Node<T>* start;
            for (start = head; start != last; start = start->next)
                std::cout << start->data << " ";
            std::cout << last->data << std::endl;
        }

};
