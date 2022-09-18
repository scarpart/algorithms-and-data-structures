#include <iostream>
#include "CircularLinkedList.cpp"

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
            soldiers.Insert(i);

        int current = 1;
        while (soldiers.Size() != 1)
        {
            current += m;
            
            soldiers.Print();

            if (current > soldiers.Size()) {
                current -= soldiers.Size();
            }

            printf("current:%d, removed index:%d, size:%d\n",
                    current, current-1, soldiers.Size());

            if (soldiers.Size() <= m) {
                soldiers.Remove(++current-1);
            } else {
                soldiers.Remove(current-1);
            }

            soldiers.Print();

        }

        int resultado = soldiers.Top(); 
        printf("Usando n=%d, m=%d, resultado=%d\n", n, m, resultado);
    }
    
    return 0;
}
