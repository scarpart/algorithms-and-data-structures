#include <string.h>
#include <iostream>

class HashTable
{
    int vsize;
    std::string* vector;

    void initializeVector(std::string* vector, int size)
    {
        for (int i = 0; i < vsize; i++)
            vector[i] = "-1";
    }

    int hash(std::string s, int n)
    {
        return s.length() % n;
    }

    public:
    
    HashTable(int n) 
    { 
        vsize = n; 
        vector = new std::string[vsize];
        initializeVector(vector, vsize);
    }

    void add(std::string s)
    {
        int h = hash(s, vsize);

        if (vector[h] == "-1" || vector[h] == "-2")
            vector[h] = s;
        else {
            while (vector[h] != "-1" && vector[h] != "-2")
                h = ++h % vsize;
            vector[h] = s;
        }
    }

    void remove(std::string s)
    {
        int h = hash(s, vsize);

        while (vector[h] != s)
            h = ++h % vsize;
        vector[h] = "-2";
    }

    void print()
    {
        for (int i = 0; i < vsize; i++)
            printf("%s\n", vector[i].c_str());
    }

};
