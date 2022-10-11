#include <iostream>
#include <string.h>
#include "ExpressionTree.cpp"

int main()
{
    ExpressionTree ep;
    std::string input;
    std::cin >> input;
    
    ep.createTree(input, NULL);

    Node* root = ep.getRoot();
    std::string prefix = "";
    std::string postfix = "";

    ep.prefix(root, &prefix);
    ep.postfix(root, &postfix);

    printf("%s\n%s\n", prefix.c_str(), postfix.c_str());

    return 0;
}
