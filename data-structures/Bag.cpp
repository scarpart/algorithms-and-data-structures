#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

template <typename T> class Bag
{
    private:
        friend class Node<T>;
        Node<T>* head = NULL;
        Node<T>* last = NULL;
        int n = 0; /*keeps track of bag size */

    public:
        void Add(T data)
        {
            if (!IsEmpty()) {
                Node<T>* newNode = new Node<T>();
                newNode->data = data;
                newNode->next = last->next;
                last->next = newNode;
                last = newNode;
            } else {
                head = last = new Node<T>();
                head->data = data;
                head->next = NULL;
            }
            n++;
        }

        void Print()
        {
            Node<T>* start;
            for (start = head; start != last; start = start->next)
                std::cout << start->data << " ";
            std::cout << last->data << std::endl;
        }

        bool IsEmpty() { return (head == NULL); }
        
        int Size() { return n; }

};

int main()
{
    Bag<int> mybag;
    mybag.Add(5);
    mybag.Add(10);
    mybag.Add(78);

    std::cout << "is the bag empty? " << mybag.IsEmpty() << std::endl;
    std::cout << "size of bag: " << mybag.Size() << std::endl;
    mybag.Print();

    return 0;
}
