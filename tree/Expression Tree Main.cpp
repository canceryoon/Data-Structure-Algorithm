#include "Expression Tree.h"

int main()
{
    ETNode* head = NULL;

    char expression[20] = "12-3*34-4+2/2+1";
    ET_BuildExpressionTree( expression, &head);

    std::cout << "Preorder" << std::endl;
    ET_PreorderPrintTree(head);
    std::endl;

    std::cout << "Inorder" << std::endl;
    ET_InorderPrintTree(head);
    std::endl;

    std::cout << "Postorder" << std::endl;
    ET_PostorderPrintTree(head);
    std::endl;

    std::cout << "Evaulation Ret: " << ET_Evaluate(head) << std::endl;
    ET_DestoryTree(head);
    return 0;
}