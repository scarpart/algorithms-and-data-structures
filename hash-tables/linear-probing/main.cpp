#include <iostream>
#include <string>
#include "../../data-structures/HashTable.cpp"

int hash(std::string s, int vectorSize);

int main() 
{
    int m;
    std::cin >> m;

    int op;
    std::string s;

    HashTable hashTable = HashTable(m);

    while (1)
    {
        std::cin >> op;
        if (op == -1) break; 
        std::cin >> s;
        
        if (op == 0)
            hashTable.add(s);
        else if (op == 1)
            hashTable.remove(s);
    }

    hashTable.print();

    return 0;
}

