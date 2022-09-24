#include <iostream>
#include "CircularLinkedList.cpp"

int solveJosephus(int n, int m, Node<int>* p);

int main()
{
    CircularLinkedList<int> mylist;
    
    int cases, n, m;
    std::cin >> cases;
    
    for (int i = 0; i < cases; i++)
    {
        std::cin >> n;
        std::cin >> m;
        CircularLinkedList<int> soldiers;

        for (int i = 1; i <= n; i++)
            soldiers.append(i);

        int resultado = solveJosephus(n, m, soldiers.top());
        printf("Usando n=%d, m=%d, resultado=%d\n", n, m, resultado);
    }
    
    return 0;
}

/**
 * Solves the Josephus problem.
 *
 * Uses the size of the list, step and a node pointer to
 * efficiently traverse the data structure and perform 
 * the needed operations.
 *
 * @param n Number of elements in the list
 * @param m The step used to traverse the list
 * @param p Pointer to the 'first' element of the list
 * @return The data from the last remaining Node.
 */
int solveJosephus(int n, int m, Node<int>* p)
{
    while (n > 1)
    {
        for (int i = 1; i < m; i++) 
            p = p->next;

        if (m % n == 0)
            p = p->next;

        Node<int>* temp = p->next;
        p->next = temp->next;
        //std::cout << "Removed " << temp->data << std::endl;
        delete temp;
        p = p->next;
        n--;
    }

    return p->data;
}