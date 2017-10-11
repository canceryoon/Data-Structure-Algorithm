#include <iostream>
#include "HashTable.h"

void printMenu()
{
	std::cout << " " << std::endl;
	std::cout << "==== HASH TABLE ==== " << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "1. Set Hash Table " << std::endl;
	std::cout << "2. Print Hash Table N" << std::endl;
}

int main()
{
	int num;
	int key, value;
	
	std::cout << "Input table size : " ;
	std::cin >> num;
	
	HashTable h(num);
	
	while(num != 0)
	{
		printMenu();
		std::cin >> num;
		
		switch(num)
		{
			case 0:  // quit 
				break;
			case 1:  // set
				std::cout << "input key " ;
				std::cin >> key;
				std::cout << "input value " ;
				std::cin >> value;
				if( h.set(key, value) )
					std::cout << "Success set Hash Table" << std::endl;
				else	
					std::cout << "Fail set Hash Table: Full hash table " << std::endl;
				break;
				
			case 2:  // get
				std::cout << "input key " ;
				std::cin >> key;
				std::cout << h.get(key) << std::endl;
				break;
				
			default : std::cout << "Wrong typed num. (1~3)" << std::endl;
		}
	}
	
	return 1;
}