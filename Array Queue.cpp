#include<iostream>
void InQueue(int* q, int data, int* f, int* r, int max)
{
    if( *r >= max )
    {
        std::cout << "Overflow. " << std::endl;
    }
    else
    {
        q[(*r)++] = data;
    }
}

void DeQueue(int* q, int* f, int* r)
{
    if( *f == *r )
    {
        std::cout << "UnderFlow" << std::endl;
    }
    else
    {
        std::cout << "Delete Queue Data:" << q[*f] << std::endl;
        for(unsigned int i = 0; i < *r ; i++)
        {
            q[i] = q[i+1];
        }
        (*r)--;
    }
}

void PrintQueue(int* q, int r)
{
    if( r == 0 ){ std::cout << "No create Queue." << std::endl; return;}
    for(unsigned int i = 0; i < r; i++)
    {
        std::cout << q[i] << " " ;
    }
    std::cout << "\n" ;
}

int main()
{
    int n;
    int size;
    int data;
    int f = 0;
    int r = 0;

    std::cout << "Enter the Queue Size: " << std::endl;
    std::cin >> size;

    int* q = new int[size];

    do
    {
        std::cout << "1. Insert Queue   2. Delete Queue   3. Print Queue   4. End " << std::endl;
        std::cin >> n;

        switch(n)
        {
            case 1: std::cout << "Insert Queue\nEnter the data : " << std::endl;
                    std::cin >> data;
                    InQueue(q, data, &f, &r, size);
                    std::cout << f << " " << r << std::endl;
                    break;
            case 2: std::cout << "Delete Queue " << std::endl;
                    DeQueue(q, &f, &r);
                    break;
            case 3: std::cout << "Print Queue " << std::endl;
                    PrintQueue(q, r);
                    break;
        }
    
    }while(n != 4);
    delete[] q;
    return 1;
}