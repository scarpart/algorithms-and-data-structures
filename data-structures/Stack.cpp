#include <iostream>

template <typename T> class Node
{
    public:
        T data;
        Node<T>* next;
};

/* pushdown (LIFO) stack */
template <typename T> class Stack
{
    private:
        friend class Node<T>;
        Node<T>* top = NULL;
        int n = 0; /* represents length of stack */

    public:
        void Push(T data)
        {
            Node<T>* oldtop = top;
            top = new Node<T>();
            top->data = data;
            top->next = oldtop;
            n++;
        }

        T Pop()
        {
            Node<T>* removed = top;
            top = top->next;
            T removedData = removed->data;
            delete removed;
            n--;
            return removedData;
        }

        bool IsEmpty()
        {
            return top == NULL;
        }

        int Size()
        {
            return n;
        }

        /* prints top data */
        void Top()
        {
            if (!IsEmpty()) printf("The element at the top is: %d\n", top->data);
            else            printf("The list is empty.\n");
        }

};

int main()
{
    Stack<int> myStack;
    
    myStack.Push(5);
    myStack.Push(10);
    std::cout << "Popped value: "
        << myStack.Pop() << std::endl;
    
    std::cout << "Size of stack: "
        << myStack.Size() << std::endl;

    std::cout << "Is stack empty? "
        << myStack.IsEmpty() << std::endl;

    myStack.Top();

    return 0;
}
