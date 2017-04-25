#include "calculator.h"

int isNum( char cipher )
{
    if( ('0' <= cipher && cipher <= '9') || cipher == '.') return 1;
    return 0;
}

unsigned int getToken( char* expression, char* token, int* type )
{   
    unsigned int i;
    for( i = 0; i != expression[i]; i++)
    {
        token[i] = expression[i];
        if(isNum( token[i] ))
        {
            *type = OPERAND;
            if(!isNum( token[i+1] )) break;
        }
        else
        {
            *type = expression[i];
            break;
        }
    }
    token[++i] = '\0';
    return i;
}

int getPriority(char Operator, int inStack)
{
    int priority = -1;
    switch(Operator)
    {
        case LEFT_PARENTHESIS :
        case RIGHT_PARENTHESIS :
            if(inStack) priority = 3;
            else priority = 0;
            break;

        case MULTIPLY :
        case DIVIDE :
            priority = 1;
            break; 

        case PLUS :
        case MINUS :
            priority = 2;
            break;
    }
    return priority;
}

int isPrior( char operator1, char operator2 )
{
    return (getPriority(operator1, 1) > getPriority(operator2, 0));
}

void getPostFix( char* inFixExpression, char* postFixExpression )
{
    LLStack* stack;
    char token[32];
    int type = -1;
    unsigned int pos = 0;
    unsigned int len = strlen(inFixExpression);

    LLS_CreateStack(&stack);

    while( pos < len )
    {
        pos += getToken( &inFixExpression[pos], token, &type );
        if( type == OPERAND )
        {
            strcat( postFixExpression, token );
            strcat( postFixExpression, " " );
        }
        else if( type == RIGHT_PARENTHESIS )
        {
            while( stack->list != NULL)
            {
                Node* pop = LLS_Pop( stack );

                if( pop->data[0] == LEFT_PARENTHESIS )
                {
                    LLS_DestroyNode( pop );
                    break;
                }
                else
                {
                    strcat( postFixExpression, pop->data );
                    LLS_DestroyNode( pop );
                }
            }
        }
        else
        {
            while( (stack->list != NULL) && !isPrior( LLS_Top(stack)->data[0], token[0]) )
            {
                Node* pop = LLS_Pop(stack);
                if( pop->data[0] != LEFT_PARENTHESIS ) strcat(postFixExpression, pop->data);
                LLS_DestroyNode(pop);
            }
            LLS_Push( stack, LLS_CreateNode( token ));
        }
    }

    while( stack->list != NULL )
    {
        Node* pop = LLS_Pop(stack);
        if( pop->data[0] != LEFT_PARENTHESIS )strcat(postFixExpression, pop->data);
        LLS_DestroyNode(pop);
    }

    LLS_DestroyStack(stack);
}

double calculate( char* postFixExpression )
{
    LLStack* stack;
    Node* Ret;
    char token[32];
    double ret;
    int type = -1;
    unsigned int read = 0;
    unsigned int len = strlen(postFixExpression);

    LLS_CreateStack(&stack);

    while( read < len )
    {
        read += getToken( &postFixExpression[read], token, &type);
        if(type == SPACE) continue;
        if(type == OPERAND)
        {
            Node* node = LLS_CreateNode( token );
            LLS_Push(stack, node);
        }
        else
        {
            char result[32];
            double oper1, oper2, tmpRet ;
            Node* operNode;

            operNode = LLS_Pop(stack);
            oper2 = atof(operNode->data);
            LLS_DestroyNode(operNode);

            operNode = LLS_Pop(stack);
            oper1 = atof(operNode->data);
            LLS_DestroyNode(operNode);

            switch(type)
            {
                case PLUS     : tmpRet = oper1 + oper2; break;
                case MINUS    : tmpRet = oper1 - oper2; break;
                case MULTIPLY : tmpRet = oper1 * oper2; break;
                case DIVIDE   : tmpRet = oper1 / oper2; break;

            }

            gcvt(tmpRet, 10, result);
            LLS_Push(stack, LLS_CreateNode(result));
        }
    }

    Ret = LLS_Pop(stack);
    ret = atof(Ret->data);
    LLS_DestroyNode(Ret);
    LLS_DestroyStack(stack);

    return ret;    
}