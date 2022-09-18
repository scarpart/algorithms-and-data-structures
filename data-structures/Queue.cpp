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
        void Enqueue(T data)
        {
            if (!IsEmpty()) {
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

        T Dequeue()
        {
            if (!IsEmpty()) {
                Node<T>* oldhead = head;
                T data = oldhead->data;
                head = oldhead->next;
                delete oldhead;
                n--;
                return data;
            }

            return -1;
        }

        bool IsEmpty()
        {
            return (head == NULL);
        }

        int Size()
        {
            return n;
        }
        
        void Print()
        {
            Node<T>* start;
            for (start = head; start != last; start = start->next)
                std::cout << start->data << " ";
            std::cout << last->data << std::endl;
        }

};

int main()
{
    Queue<int> myq;
    myq.Enqueue(5);
    myq.Enqueue(10);

    std::cout << "Dequeued value: " << myq.Dequeue() << std::endl;
    
    std::cout << "Is myq empty? " << myq.IsEmpty() << std::endl;
    std::cout << "Size of myq: " << myq.Size() << std::endl;
    myq.Print();

    return 0;
}





