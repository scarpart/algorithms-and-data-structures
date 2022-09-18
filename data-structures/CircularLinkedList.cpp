#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

template <typename T> class CircularLinkedList
{
    public:
        friend class Node<T>;

        Node<T>* cursor = NULL;
        int n = 0;

        void Insert(T data)
        {
            Node<T>* newNode = new Node<T>();
            newNode->data = data;
            newNode->next = cursor->next;
            if (!IsEmpty())
                cursor->next = newNode;
            cursor = newNode;
            n++;
        }

        void Remove(int index)
        {
            Node<T>* p;
            int i = 0;
            for (p = cursor->next; i < index; p = p->next)
                i++;
            Node<T>* removed = p->next;
            p->next = removed->next;
            delete removed;
            n--;
        }

        void Print()
        {
            Node<T>* p;
            for (p = cursor->next; p != cursor; p = p->next)
                std::cout << p->data << " ";
            std::cout << cursor->data << std::endl;
        }

        int Length()   { return n; }

        bool IsEmpty() { return cursor == NULL; }

};


int main()
{
    CircularLinkedList<int> mylist;
    
    std::cout << "Inserting elements 7 and 10...\n";
    mylist.Insert(7);
    mylist.Insert(10);
    
    std::cout << "Removing elements 10 and 7...\n";
    mylist.Remove(1);
    mylist.Remove(0);

    std::cout << "Legnth of list: " << mylist.Length() << std::endl;
    std::cout << "Is the list empty? " << mylist.IsEmpty() << std::endl;

    mylist.Insert(100);
    mylist.Insert(300);
    mylist.Insert(-7);
    mylist.Print();

    return 0;
}





