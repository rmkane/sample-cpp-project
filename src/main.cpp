#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
  LinkedList<int> list;

  // Add few items to the end of LinkedList
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  std::cout << "Size: " << list.size() << std::endl;

  std::cout << "Traversing LinkedList through method:" << std::endl;
  list.print();

  std::cout << "Traversing LinkedList through Iterator:" << std::endl;
  for (LinkedList<int>::Iterator iterator = list.begin();
       iterator != list.end(); iterator++)
  {
    std::cout << *iterator << " ";
  }

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
