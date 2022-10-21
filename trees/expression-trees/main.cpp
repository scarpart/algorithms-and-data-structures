#include <iostream>
#include <string.h>
#include "../../data-structures/ExpressionTree.cpp"

int main()
{
    ExpressionTree ep;
    std::string input;
    std::cin >> input;
    
    ep.createTree(input, NULL);
    printf("%s\n%s\n", ep.prefix().c_str(), ep.postfix().c_str());

    return 0;
}
