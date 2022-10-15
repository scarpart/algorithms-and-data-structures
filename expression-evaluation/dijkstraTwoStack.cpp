#include <iostream>
#include <math.h>

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
    Stack<char> ops;
    Stack<double> vals;
    char c;

    while ((c = getchar()) != '\n')
    {
        if      (c == '(');
        else if (c == '+')    ops.Push(c);
        else if (c == '*')    ops.Push(c);
        else if (c == '/')    ops.Push(c);
        else if (c == 's')    ops.Push(c);
        else if (c == ')') {
            char op = ops.Pop();
            double v = vals.Pop();
            if      (c == '+')    v = vals.Pop() + v;
            else if (c == '*')    v = vals.Pop() * v;
            else if (c == '/')    v = vals.Pop() / v;
            else if (c == 's')    v = std::sqrt(v);
            vals.Push(v);
        }
        else vals.Push((double)c-'0');
    }
    printf("%f\n", vals.Pop());

    return 0;
}
