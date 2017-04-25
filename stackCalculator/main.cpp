#include<iostream>
#include "calculator.h"

int main()
{
    char inFixExpression[100];
    char postFixExpression[100];
    double ret = 0.0;

    memset(inFixExpression, 0 ,sizeof(inFixExpression));
    memset(postFixExpression, 0 ,sizeof(postFixExpression));

    std::cout << "Enter infix Expression: " << std::endl;
    std::cin >> inFixExpression ;

    getPostFix(inFixExpression, postFixExpression);
    std::cout << "infix: " << inFixExpression << " postfix: " << postFixExpression << std::endl;
    
    ret = calculate(postFixExpression);

    std::cout << "Ret: [" << ret << "]" << std::endl;


    return 1;
}