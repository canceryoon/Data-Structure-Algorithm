#include<iostream>

typedef int DATA;

struct Node{
    DATA data;
};

struct stackArray{
    int Top;
    int Capacity;
    Node* data;
};
//AS: Array Stack.

void AS_Create(stackArray** st, int Capacity)
{
    (*st) = (stackArray*)malloc(sizeof(stackArray));
    (*st)->data = (Node*)malloc(sizeof(Node));

    (*st)->Capacity = Capacity;
    (*st)->Top = 0;
}

void AS_Destory(stackArray *st)
{
    free(st->data);
    free(st);
}

void AS_Push(stackArray *st, int _data)
{
    st->data[st->Top++].data = _data;
}

DATA AS_Pop(stackArray *st)
{
    return st->data[--st->Top].data;
}

DATA AS_Top(stackArray *st)
{
    return st->data[st->Top - 1].data;
}

int AS_getSize(stackArray *st)
{
    return st->Top;
}

int AS_isTemp(stackArray *st)
{
    return st->Top == 0;
}


int main()
{
    int x, _data;
    stackArray* st = NULL;

    std::cout << "Create STACK. Input Capacity: " ;
    std::cin >> x ;
    AS_Create(&st, x);
    do
    {
        std::cout << "0. End  1. Push   2. Pop   3. Top   4. Size  " << std::endl;
        std::cin >> x;
        switch(x)
        {
            case 1: if( AS_getSize(st) == st->Capacity )
                    {
                        std::cout << "Full stack. Overflows. " << std::endl;    
                        break;
                    }
                    std::cout << "Input data: " << std::endl;
                    std::cin >> _data;
                    AS_Push(st, _data);
                    break;
            case 2: std::cout << "Top Data: " << AS_Pop(st) << std::endl; 
                    break;
            case 3: std::cout << "Top Data: " << AS_Top(st) << std::endl; 
                    break;
            case 4: std::cout << "Stack Size: " << AS_getSize(st) << std::endl; 
                    break;
        }
    }while( x != 0 );
    AS_Destory(st);
    return 1;
}