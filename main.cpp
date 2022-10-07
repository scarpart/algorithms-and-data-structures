#include <iostream>
#include <string.h>
#include "ExpressionTree.cpp"

int main()
{
    ExpressionTree ep;
    std::string input;
    std::cin >> input;
    
    ep.createTree(input, NULL);
    ep.prefix(NULL);
    ep.postfix(NULL);

    return 0;
}