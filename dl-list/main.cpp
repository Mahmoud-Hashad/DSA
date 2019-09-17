#include <iostream>
#include "dlist.h"

using namespace std;

int main()
{
  dlist<int> test;
  test.pushBack(190);
  test.pushBack(3);
  test.pushBack(40);
  test.pushBack(-43);
  test.pushBack(-3);
  test.pushBack(1);
  test.pushBack(10);
  test.pushBack(0);
  test.pushBack(10);
  test.pushBack(23);
  test.pushBack(1);
  test.pushBack(90);
  test.print();
  test.sort();
  test.print();


  return 0;
}
