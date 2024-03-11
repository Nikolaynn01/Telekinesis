#include <iostream>
#include "forward_list.h"

int main()
{
	forward_list<int> myList;
       	myList.push_front(3);
    	myList.push_front(2);
    	myList.push_front(1);

    	std::cout << "Front element: " << myList.front() << std::endl;

	myList.pop_front();

    	std::cout << "Front element after pop: " << myList.front() << std::endl;

    	return 0;
}
