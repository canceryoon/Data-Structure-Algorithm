#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<iostream>
#include<stdlib.h>
#include "Linked List Stack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
}Operator;

int isNum( char cipher );
unsigned int getToken( char* expression, char* token, int* type);
int isPrior( char operator1, char operator2 );
void getPostFix( char* inFixExpression, char* postFixExpression );
double calculate( char* postFixExpression);
#endif	