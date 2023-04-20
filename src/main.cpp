#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
  LinkedList<bool> boolList;
  boolList.print();

  LinkedList<string> strList;
  strList.add("Hello");
  cout << strList.get(0) << endl;
  strList.print();

  LinkedList<int> numberList;
  numberList.add(4);
  numberList.add(2);
  cout << numberList.get(0) << endl;
  cout << numberList[1] << endl;
  numberList.print();

  return EXIT_SUCCESS;
}
