#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

template <typename T> class LinkedList
{
    public:
        friend class Node<T>;

        Node<T>* head = NULL;

        void Append(T data)
        {
            if (IsEmpty()) { InsertAsFirstElement(data); }
            else
            {
                Node<T>* newNode = new Node<T>();
                Node<T>* p = head;
                while (p->next != NULL) p = p->next;
                newNode->next = NULL;
                newNode->data = data;
                p->next = newNode;
            }
        }

        void Insert(int index, T data)
        {
            if (!index) InsertAsFirstElement(data);
            else
            {
                Node<T>* p = head;
                int i;
                for (i = 0; i < index-1; i++) p = p->next;
                Node<T>* newNode = new Node<T>();
                newNode->data = data;
                newNode->next = p->next; 
                p->next = newNode;
            }
        }

        void Remove(int index)
        {
            if (!index) RemoveFirstElement();
            else
            {
                int i;
                Node<T>* p = head;
                for (i = 1; i < index; i++) p = p->next;
                Node<T>* removed = p->next;
                p->next = removed->next;
                delete removed;
            }
        }

        int Length()
        {
            Node<T>* p = head;
            int i;
            for (i = 0; p->next != NULL; p = p->next) i++;
            return ++i;
        }

        void Print()
        {
            Node<T>* p = head;
            while (p->next != NULL)
            {
                std::cout << p->data << " ";
                p = p->next;
            }
            std::cout << p->data << std::endl;
        }

        bool IsEmpty()
        {
            return (head == NULL);
        }

    private:
        void RemoveFirstElement()
        {
            Node<T>* removed = head;
            head = removed->next;
            delete removed;
        }

        void InsertAsFirstElement(T data)
        {
            Node<T>* p = new Node<T>();
            p->data = data;
            p->next = NULL;
            head = p;
        }
};

int main()
{
    LinkedList<int> myList;
    std::cout << "Is myList empty? " << myList.IsEmpty() << std::endl;
    myList.Append(56);
    myList.Append(70);
    myList.Append(8);
    myList.Append(10);
    myList.Remove(2);
    myList.Print();
    std::cout << "Length of myList: " << myList.Length() << std::endl;
    myList.Insert(2, 5555);
    myList.Print();

    return 0;
}

